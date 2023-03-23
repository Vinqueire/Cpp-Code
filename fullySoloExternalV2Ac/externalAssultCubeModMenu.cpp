#include "pch.h"
#include "proc.h"
#include "mem.h"

void printWelcome(HANDLE consoleText, WORD baseColour, bool first);

void logCurState(bool bHealth, bool bAmmo, bool bRecoil, WORD goodColor, WORD badColor, HANDLE consoleText, WORD baseColour, int depth);

void errorLog(HANDLE consoleText);

int main()
{
	DWORD procId = getProcId(L"ac_client.exe");
	uintptr_t modAddr = getModuleBaseAddress(procId, L"ac_client.exe");
	HANDLE consoleText = GetStdHandle(STD_OUTPUT_HANDLE);

	if (procId == 1)
	{
		errorLog(consoleText);
		system("pause");
		return 1;
	}

	uintptr_t dynAddr = modAddr + 0x10F4F4;

	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

	std::vector<unsigned int> healthOffset = { 0xF8 };

	uintptr_t healthAddress = findDMAAddy(hProc, dynAddr, healthOffset);

	WORD baseColour = 15;
	WORD goodColor = 10;
	WORD badColor = 4;
	int depth = 68;
	const int newValue = 777;

	printWelcome(consoleText, baseColour , true);
	bool bHealth = false, bAmmo = false, bRecoil = false, cheatActivated = false;

	DWORD exitCode;

	if (GetExitCodeProcess(hProc, &exitCode) && exitCode == STILL_ACTIVE)
	{
		while (1)
		{
			if (GetAsyncKeyState(VK_NUMPAD5) & 1)
			{ 
				system("cls");

				printWelcome(consoleText, baseColour, false);
				logCurState(bHealth, bAmmo, bRecoil, goodColor, badColor, consoleText, baseColour, depth);

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
						WriteProcessMemory(hProc, (BYTE*)healthAddress, &newValue, sizeof(newValue), 0);

					if (cheatActivated)
					{
						system("cls");
						printWelcome(consoleText, baseColour, false);

						logCurState(bHealth, bAmmo, bRecoil, goodColor, badColor, consoleText, baseColour, depth);

						cheatActivated = false;
					}

					Sleep(50);
				}
			}
		}
	}

	system("pause");
	return 0;
}



void printWelcome(HANDLE consoleText, WORD baseColour, bool first)
{
	SetConsoleTextAttribute(consoleText, baseColour);

	if (first)
	{
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
		std::cout << std::setw(70) << "Jourvence Mod Menu\n\n";
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
		std::cout << std::setw(77) << "To Activate Ammo Cheat Press Numpad5\n\n";
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";;
	}
	else
	{
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
		std::cout << std::setw(70) << "Jourvence Mod Menu\n\n";
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
		std::cout << std::setw(75) << "To Activate Godmode Press Numpad1\n";
		std::cout << std::setw(77) << "To Activate Ammo Cheat Press Numpad2\n";
		std::cout << std::setw(80) << "To Activate Recoil Cheat Press Numpad3\n\n\n";
		std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";;
	}
}



void logCurState(bool bHealth, bool bAmmo, bool bRecoil, WORD goodColor, WORD badColor, HANDLE consoleText, WORD baseColour, int depth)
{
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

}



void errorLog(HANDLE consoleText)
{
	SetConsoleTextAttribute(consoleText, 4);
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	std::cout << std::setw(70) << "Jourvence Mod Menu\n\n";
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	std::cout << std::setw(71) << "TURN ON ASSAULT CUBE\n\n";
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";;
	SetConsoleTextAttribute(consoleText, 10);
}