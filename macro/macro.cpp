#include <iostream>
#include <thread>
#include <Windows.h>
#include <winuser.h>

void klikacz(char key);

int main()
{
	int i = 0;
	int j = 0;
	std::cout << "How many time's do you want to spam?\n";
	std::cin >> j;
	Sleep(5000);

	while (i < j)
	{
		Sleep(1);
		klikacz(0x14);
		klikacz(0x45);
		klikacz(0x14);
		klikacz(0x4E);
		klikacz(0x4A);
		klikacz(0x4F);
		klikacz(0x59);
		klikacz(VK_SPACE);
		klikacz(0x46);
		klikacz(0x45);
		klikacz(0x57);
		klikacz(VK_SPACE);
		klikacz(0x4D);
		klikacz(0x4F);
		klikacz(0x52);
		klikacz(0x45);
		klikacz(0x0D);
		i++;
	}

	return 0;

}

void klikacz(char key) {
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = key;
	ip.ki.wScan = 0;
	ip.ki.dwFlags = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
};

//klikacz(0x41); -a
//klikacz(0x42); -b
//klikacz(0x43); -c
//klikacz(0x44); -d
//klikacz(0x45); -e
//klikacz(0x46); -f
//klikacz(0x47); -g
//klikacz(0x48); -h
//klikacz(0x49); -i
//klikacz(0x4a); -j
//klikacz(0x4b); -k
//klikacz(0x4c); -l
//klikacz(0x4d); -m
//klikacz(0x4e); -n
//klikacz(0x4f); -o
//klikacz(0x50); -p
//klikacz(0x51); -q
//klikacz(0x52); -r
//klikacz(0x53); -s
//klikacz(0x54); -t
//klikacz(0x55); -u
//klikacz(0x56); -v
//klikacz(0x57); -w
//klikacz(0x58); -x
//klikacz(0x59); -y
//klikacz(0x5a); -z
//
//klikacz(0x30); -0
//klikacz(0x31); -1
//klikacz(0x32); -2
//klikacz(0x33); -3
//klikacz(0x34); -4
//klikacz(0x35); -5
//klikacz(0x36); -6
//klikacz(0x37); -7
//klikacz(0x38); -8
//klikacz(0x39); -9
//
//klikacz(vk_capital); -caps lock
//klikacz(vk_return); - enter