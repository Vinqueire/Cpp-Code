#include "pch.h"
#include "proc.h"
#include "mem.h"

int main()
{
	DWORD procId = getProcId(L"ac_client.exe");
	uintptr_t modBaseAddr = getModuleBaseAddress(procId, L"ac_client.exe");
	std::cout << "Base addr is: 0x" << std::hex << modBaseAddr << std::endl;

	uintptr_t dynAddr = modBaseAddr + 0x10F4F4;
	std::cout << "Dyn addr is: 0x" << dynAddr << std::endl;

	HANDLE hProc = OpenProcess(dynAddr, 0, procId);
	std::cout << "hProc is: " << hProc << std::dec << std::endl;

	std::vector<unsigned int> healthOffset = { 0xF8 };
	std::vector<unsigned int> ammoOffset = { 0x374, 0x14, 0x0 };

	uintptr_t healthAddr = findDMAAddy(hProc, dynAddr, healthOffset);

	bool bHealth = false, bAmmo = false;
	int updatedHealth = 777;

	DWORD isProcRunning = 0;
	if (GetExitCodeProcess(hProc, &isProcRunning) && isProcRunning == STILL_ACTIVE)
	{
		while (1)
		{
			if (GetAsyncKeyState(VK_NUMPAD1) & 1)
			{
				bHealth = !bHealth; 
				if (bHealth)
					std::cout << "Godmode Activated\n";
				else
					std::cout << "Godmode Decactivated\n";
			}

			if (GetAsyncKeyState(VK_NUMPAD2) & 1)
			{
				bAmmo = !bAmmo;

				if (bAmmo)
				{
					mem::patchEx((BYTE*)(modBaseAddr + 0x637e9), (BYTE*)"\xFF\x06", 2, hProc);
					std::cout << "Ammo cheat activated\n";
				}
				else
				{
					mem::patchEx((BYTE*)(modBaseAddr + 0x637e9), (BYTE*)"\xFF\x0E", 2, hProc);
					std::cout << "Ammo cheat deactivated\n";
				}
			}
			
			if (bHealth)
			{
				mem::patchEx((BYTE*)healthAddr, (BYTE*)&updatedHealth, sizeof(updatedHealth), hProc);
			}
			Sleep(25);
		}
	}
	
	system("pause");
	return 0;
}