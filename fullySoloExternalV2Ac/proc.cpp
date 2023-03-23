#include "pch.h"
#include "proc.h"

DWORD getProcId(const wchar_t* procName)
{
	DWORD procId = 0;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (snapshot == INVALID_HANDLE_VALUE)
	{
		std::cout << "getProcId snapshot has invalid value\n";
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
		std::cout << "getProcId procId is 0\n";
		return 1;
	}
	return procId;
}

uintptr_t getModuleBaseAddress(DWORD procId, const wchar_t* modName)
{
	uintptr_t modAddr = 0;
	HANDLE modSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);

	if (modSnap == INVALID_HANDLE_VALUE)
	{
		std::cout << "getModuleBaseAddress modSnap has invalid value\n";
		return 1;
	}

	MODULEENTRY32 entry;
	entry.dwSize = sizeof(entry);

	if (Module32First(modSnap, &entry))
	{
		do
		{
			if (!_wcsicmp(entry.szModule, modName))
			{
				modAddr = (uintptr_t)entry.modBaseAddr;
				break;
			}
		}
		while (Module32Next(modSnap, &entry));
	}
	CloseHandle(modSnap);
	if (modAddr == 0)
	{
		std::cout << "getModuleBaseAddress modAddr has value 0\n";
		return 1;
	}
	return modAddr;
}

uintptr_t findDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;

	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	return addr;
}