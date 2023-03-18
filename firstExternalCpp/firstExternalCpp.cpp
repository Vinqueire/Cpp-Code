#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"

int main()
{
	// Get id of targer process
	DWORD procId = GetProcId(L"ac_client.exe");
	// Get module base adress
	uintptr_t moduleBase = GetModuleBaseAdress(procId, L"ac_client.exe");

	// Get handle to the process
	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	// Resolve base adress
	uintptr_t dynamicPtrBaseAddr = moduleBase + 0x10f4f4;

	std::cout << "Dynamic Ptr base adress = " << "0x" << std::hex 
		<< dynamicPtrBaseAddr << std::endl;

	// Resolve ammo pointer chain 
	std::vector<unsigned int> ammoOffsets = {0x374, 0x14, 0x0};
	std::vector<unsigned int> healthOffsets = { 0xF8 };

	uintptr_t ammoAddr = findDMAAaddy(hProcess, dynamicPtrBaseAddr,
		ammoOffsets);
	uintptr_t healthAddr = findDMAAaddy(hProcess, dynamicPtrBaseAddr,
		healthOffsets);

	std::cout << "ammo address: " << "0x" << std::hex
		<< ammoAddr << std::endl;


	// Read out the ammo value
	int ammoValue = 0;

	ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue),
		nullptr);
	std::cout << "Current ammo = " << std::dec << ammoValue << std::endl;


	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &ammoValue, sizeof(ammoValue),
		nullptr);

	// Write to ammo value
	int newAmmo = 1337;
	while (1)
	{
	ammoAddr = findDMAAaddy(hProcess, dynamicPtrBaseAddr,
			ammoOffsets);
	ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue),
		nullptr);
	WriteProcessMemory(hProcess, (BYTE*)ammoAddr, &newAmmo, sizeof(newAmmo),
			nullptr);
	WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newAmmo, sizeof(newAmmo),
		nullptr);
	}

	// Read it again to comfirm it works
	ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue),
		nullptr);
	
	std::cout << "new ammo = " << std::dec << ammoValue << std::endl;

	system("pause");

	return 0;
}