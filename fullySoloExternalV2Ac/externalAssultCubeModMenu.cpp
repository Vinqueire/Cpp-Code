#include "pch.h"
#include "proc.h"
#include "mem.h"

int main()
{
	DWORD procId = getProcId(L"ac_client.exe");
	uintptr_t modAddr = getModuleBaseAddress(procId, L"ac_client.exe");

	uintptr_t dynAddr = modAddr + 0x10F4F4;

	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

	std::vector<unsigned int> healthOffset = { 0xF8 };

	uintptr_t healthAddress = findDMAAddy(hProc, dynAddr, healthOffset);


	HANDLE consoleText = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD baseColour = 15;
	WORD goodColor = 10;
	WORD badColor = 4;
	SetConsoleTextAttribute(consoleText, baseColour);

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	std::cout << std::setw(70) << "Jourvence Mod Menu\n\n";
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	std::cout << std::setw(75) << "To Activate Godmode Press Numpad1\n"; 
	std::cout << std::setw(77) << "To Activate Ammo Cheat Press Numpad1\n";
	std::cout << std::setw(80) << "To Activate Recoil Cheat Press Numpad1\n\n\n";
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

	

	const std::string red = "\033[31m";
	const std::string green = "\033[32m";

	const int newValue = 777;

	DWORD exitCode;

	bool bHealth = false, bAmmo = false, bRecoil = false, cheatActivated = false;


	if (GetExitCodeProcess(hProc, &exitCode) && exitCode == STILL_ACTIVE)
	{
		while (true)
		{
			if (GetAsyncKeyState(VK_NUMPAD1) & 1)
			{
				bHealth = !bHealth;
				cheatActivated = true;
			}

			if (GetAsyncKeyState(VK_NUMPAD2) & 1)
			{
				bAmmo = !bAmmo;

				if (bAmmo)
					mem::patchEx((BYTE*)(modAddr + 0x637E9), (BYTE*)"\xFF\x06", 2, hProc);
				else
					mem::patchEx((BYTE*)(modAddr + 0x637E9), (BYTE*)"\xFF\x0E", 2, hProc);

				cheatActivated = true;
			}

			if (GetAsyncKeyState(VK_NUMPAD3) & 1)
			{
				bRecoil = !bRecoil;

				if (bRecoil)
					mem::nopEx((BYTE*)(modAddr + 0x63786), 10, hProc);
				else
					mem::patchEx((BYTE*)(modAddr + 0x63786), (BYTE*)"\x50\x8d\x4c\x24\x1c\x51\x8b\xce\xff\xd2", 10, hProc);

				cheatActivated = true;
			}

			if (bHealth)
			{
				WriteProcessMemory(hProc, (BYTE*)healthAddress, &newValue, sizeof(newValue), 0);
			}

			if (cheatActivated)
			{
				system("cls");

				SetConsoleTextAttribute(consoleText, baseColour);
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
				std::cout << std::setw(70) << "Jourvence Mod Menu\n\n";
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
				std::cout << std::setw(75) << "To Activate Godmode Press Numpad1\n";
				std::cout << std::setw(77) << "To Activate Ammo Cheat Press Numpad1\n";
				std::cout << std::setw(80) << "To Activate Recoil Cheat Press Numpad1\n\n\n";


				int depth = 68;

				if (bHealth)
				{
					SetConsoleTextAttribute(consoleText, goodColor);
					std::cout << std::setw(depth) << "[ GODMODE ] \t\t -> ON  <-\n\n";

				}
				else
				{
					SetConsoleTextAttribute(consoleText, badColor);
					std::cout << std::setw(depth) << "[ GODMODE ] \t\t -> OFF <-\n\n";

				}
				if (bAmmo)
				{
					SetConsoleTextAttribute(consoleText, goodColor);
					std::cout << std::setw(depth) << "[ AMMO CHEAT ] \t\t -> ON  <-\n\n";
				}
				else
				{
					SetConsoleTextAttribute(consoleText, badColor);
					std::cout << std::setw(depth) << "[ AMMO CHEAT ] \t\t -> OFF <-\n\n";
				}

				if (bRecoil)
				{
					SetConsoleTextAttribute(consoleText, goodColor);
					std::cout << std::setw(depth) << "[ RECOIL CHEAT ] \t\t -> ON  <-\n\n";
				}
				else
				{
					SetConsoleTextAttribute(consoleText, badColor);
					std::cout << std::setw(depth) << "[ RECOIL CHEAT ] \t\t -> OFF <-\n\n";
				}
				
				SetConsoleTextAttribute(consoleText, baseColour);
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
				cheatActivated = false;
			}

			Sleep(50);
		}
	}

	system("pause");
	return 0;
}