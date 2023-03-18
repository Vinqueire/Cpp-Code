#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

DWORD getProcessId(const wchar_t* processName);

int main()
{
	DWORD procId = getProcessId(L"ac_client.exe");
	std::cout << procId << std::endl; // This is here just so the code compiles lol

	system("pause");
	return 0;
}

DWORD getProcessId(const wchar_t* processName)
{
	PROCESSENTRY32 pe32;
	DWORD procId = 0;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (snapshot == INVALID_HANDLE_VALUE || snapshot == 0)
	{
		std::cout << "Invalid handle value";
		return 1;
	}
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(snapshot, &pe32))
	{
		do
		{
			if (!_wcsicmp(pe32.szExeFile, processName))
			{
				procId = pe32.th32ProcessID;
				std::cout << "ProcId is: " << procId << std::endl;
				break;
			}
		} while (Process32Next(snapshot, &pe32));
	}
	if (procId == 0)
	{
		std::cout << "No process assigned" << std::endl;
	}

	CloseHandle(snapshot);
	return procId;
}