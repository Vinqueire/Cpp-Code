#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

DWORD getProcId(const wchar_t* procName);
uintptr_t getModuleBaseAddress(DWORD procId, const wchar_t* modName);
uintptr_t findDMAAddy(HANDLE hproc, uintptr_t ptr, std::vector<unsigned int> offsets);

int main()
{
	DWORD procId = getProcId(L"ac_client.exe");
	std::cout << "procId is: " << procId << std::endl;
	uintptr_t baseAddr = getModuleBaseAddress(procId, L"ac_client.exe");
	std::cout << "Base adress is: 0x" << std::hex << baseAddr << std::dec << std::endl;

	HANDLE hproc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);
	std::vector<unsigned int> healthOffset = { 0xF8 };
	uintptr_t dynAddr = baseAddr + 0x10F4F4;
	std::cout << "dynamicAddr is: 0x" << std::hex << dynAddr << std::dec << std::endl;

	uintptr_t healthAddress = findDMAAddy(hproc, dynAddr, healthOffset);

	int currentHealth = 0;
	ReadProcessMemory(hproc, (BYTE*)healthAddress, &currentHealth, sizeof(currentHealth), 0);
	std::cout << "Current health is: " << currentHealth << std::endl;

	int updatedHealth = 777;
	WriteProcessMemory(hproc, (BYTE*)healthAddress, &updatedHealth, sizeof(updatedHealth), 0);
	std::cout << "Now your health is: " << updatedHealth << std::endl;


	system("pause");
	return 0;
}

DWORD getProcId(const wchar_t* procName)
{
	DWORD procId = 0;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (snapshot == INVALID_HANDLE_VALUE)
	{
		std::cout << "getProcId snapshot has invalid value" << std::endl;
		return 1;
	}

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(entry);

	if (Process32First(snapshot, &entry))
	{
		do
		{
			if (!_wcsicmp(entry.szExeFile, procName))
			{
				procId = entry.th32ProcessID;
				break;
			}
		} 
		while (Process32Next(snapshot, &entry));
	}
	CloseHandle(snapshot);
	if (procId == 0)
	{
		std::cout << "getProcId procId has value of 0, failed to get procid\n";
		return 1;
	}
	return procId;
}

uintptr_t getModuleBaseAddress(DWORD procId, const wchar_t* modName)
{
	uintptr_t modAddr = 0;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);

	if (snapshot == INVALID_HANDLE_VALUE)
	{
		std::cout << "getModuleBaseAddress snapshot has invalid value\n";
		return 1;
	}

	MODULEENTRY32 entry;
	entry.dwSize = sizeof(entry);

	if (Module32First(snapshot, &entry))
	{
		do
		{
			if (!_wcsicmp(entry.szModule, modName))
			{
				modAddr = (uintptr_t)entry.modBaseAddr;
				break;
			}
		} 
		while (Module32Next(snapshot, &entry));
	}
	CloseHandle(snapshot);
	if (modAddr == 0)
	{
		std::cout << "getModuleBaseAddress modAddr is 0, failed to get modBaseAddr\n";
		return 1;
	}
	return modAddr;
}

uintptr_t findDMAAddy(HANDLE hproc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;

	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(hproc, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	return addr;
}