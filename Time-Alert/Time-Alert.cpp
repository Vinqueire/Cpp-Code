#include <iostream>
#include <Windows.h>
#include <tchar.h>

void sound();

int main()
{
	int minutes{};

	std::cout << "Input the amount of minutes you want to countdown: ";
	std::cin >> minutes;
	std::cout << std::endl;
	int seconds = minutes * 60;

	do
	{
		if (seconds == 0)
		{
			std::cout << "TIME'S UP!" << std::endl;
			sound();
		}
		std::cout << "There are " << seconds << " seconds remaining\n";
		seconds--;
		Sleep(1000);

	} while (true);

}

void sound()
{
		for (int i = 0; i < 999; ++i)
		{
			PlaySound(TEXT("delfinbudzik.wav"), NULL, SND_SYNC);
			std::cout << "Wylacz piec\n";
			Sleep(1);
		}
}