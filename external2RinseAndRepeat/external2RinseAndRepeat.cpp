#include "pch.h"
#include "proc.h"
#include "mem.h"

int main()
{
	HANDLE hProcess = 0;
	uintptr_t modBase = 0, localPlayerPtr = 0, healthAddress = 0;
	bool bHealth = false, bAmmo = false, bRecoil = false;

	const int newValue = 1337;

	DWORD procId = getProcId(L"ac_client.exe");

	if (procId)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);
		modBase = getModuleBaseAddress(procId, L"ac_client.exe");
		localPlayerPtr = modBase + 0x10F4F4;

		healthAddress = findDMAAddy(hProcess, localPlayerPtr, { 0xF8 });
	}
	else
	{
		std::cout << "Process not found, press enter to exit\n";
		getchar();
		return 1;
	}

	DWORD dwExit = 0;

	while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
	{
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			bHealth = !bHealth;
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			bAmmo = !bAmmo;

			if (bAmmo)
			{
				// ff06 == inc [esi]
				mem::patchEx((BYTE*)(modBase + 0x637e9), (BYTE*)"\xFF\x06", 2, hProcess);
			}
			else
			{
				// ff0E == dec [esi]
				mem::patchEx((BYTE*)(modBase + 0x637e9), (BYTE*)"\xFF\x0E", 2, hProcess);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			bRecoil = !bRecoil;

			if (bRecoil)
			{
				mem::nopEx((BYTE*)(modBase + 0x63786), 10, hProcess);
			}
			else
			{
				mem::patchEx((BYTE*)(modBase + 0x63786), (BYTE*)"\x50\x8d\x4c\x24\x1c\x51\x8b\xce\xff\xd2", 10, hProcess);
			}
		}

		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			return 0;
		}

		// Continous write or freeze
		if (bHealth)
		{
			mem::patchEx((BYTE*)healthAddress, (BYTE*)&newValue, sizeof(newValue), hProcess);
		}

		Sleep(10);
	}

	std::cout << "Process not found, press enter to exit\n";

	getchar();
	return 0;
}