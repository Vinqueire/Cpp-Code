#include "pch.h"
#include "proc.h"

int main()
{
	DWORD procId = getProcId(L"ac_client.exe");
	uintptr_t modAddress = getModuleBaseAddress(procId, L"ac_client.exe");
	
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);
	
	uintptr_t dynamicAddress = modAddress + 0x10F4F4;

	if (procId == 1 || modAddress == 1)
	{
		std::cout << "Your game probably isn't open :)\n";
		return 1;
	}

	std::vector<unsigned int> healthOffset = { 0xF8 };
	std::vector<unsigned int> ammoOffset = { 0x374, 0x14, 0x0 };

	uintptr_t healthAdress = findDMAAddy(hProc, dynamicAddress, healthOffset);
	uintptr_t ammoAdress = findDMAAddy(hProc, dynamicAddress, ammoOffset);

	int currentHealth = 0;
	ReadProcessMemory(hProc, (BYTE*)healthAdress, &currentHealth, sizeof(currentHealth), 0);
	std::cout << "Your currentHealth is: " << currentHealth << std::endl;

	int currentAmmo = 0;
	ReadProcessMemory(hProc, (BYTE*)ammoAdress, &currentAmmo, sizeof(currentAmmo), 0);
	std::cout << "Your currentAmmo is: " << currentAmmo << std::endl << std::endl;

	int updatedHealth = 1337;
	int updatedAmmo = 777;

	WriteProcessMemory(hProc, (BYTE*)healthAdress, &updatedHealth, sizeof(updatedHealth), 0);
	WriteProcessMemory(hProc, (BYTE*)ammoAdress, &updatedAmmo, sizeof(updatedAmmo), 0);

	

	ReadProcessMemory(hProc, (BYTE*)healthAdress, &currentHealth, sizeof(currentHealth), 0);
	std::cout << "Your Health is now set to: " << currentHealth << std::endl;

	ReadProcessMemory(hProc, (BYTE*)ammoAdress, &currentAmmo, sizeof(currentAmmo), 0);
	std::cout << "Your Ammo is now set to: " << currentAmmo << std::endl << std::endl;


	system("pause");
	return 0;
}