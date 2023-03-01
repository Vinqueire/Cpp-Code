#include <Windows.h>
#include <iostream>
#include <string.h>

int main(void)
{
	int counter{};
	int max{};
	float sec{};
	char* word{};

	
	std::cout << "How many time's do you want to write a message: ";
	std::cin >> max;
	std::cout << "\nHow long of a delay do you want (in seconds): ";
	std::cin >> sec;
	sec = sec * 1000;
	
	int a = 0x41;
	int b = 0x42;
	int c = 0x43;
	int d = 0x44;
	int e = 0x45;
	int f = 0x46;
	int g = 0x47;
	int h = 0x48;
	int i = 0x49;
	int j = 0x4A;
	int k = 0x4B;
	int l = 0x4C;
	int m = 0x4D;
	int n = 0x4E;
	int o = 0x4F;
	int p = 0x50;
	int q = 0x51;
	int r = 0x52;
	int	s = 0x53;
	int	t = 0x54;
	int	u = 0x55;
	int	v = 0x56;
	int	w = 0x57;
	int	x = 0x58;
	int y = 0x59;
	int z = 0x5A;

	int num0 = 0x30;
	int num1 = 0x31;
	int num2 = 0x32;
	int num3 = 0x33;
	int num4 = 0x34;
	int num5 = 0x35;
	int num6 = 0x36;
	int num7 = 0x37;
	int num8 = 0x38;
	int num9 = 0x39;

	int space = 0x20;
	int caps = 0x14;
	int enter = 0x0D;

	Sleep(5000);
	while (counter < max) 
	{
		Sleep(sec);
		keybd_event(caps, 0, 1, 0);
		keybd_event(caps, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(j, 0, 1, 0);
		keybd_event(caps, 0, 1, 0);
		keybd_event(caps, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(o, 0, 1, 0);
		keybd_event(u, 0, 1, 0);
		keybd_event(r, 0, 1, 0);
		keybd_event(v, 0, 1, 0);
		keybd_event(e, 0, 1, 0);
		keybd_event(n, 0, 1, 0);
		keybd_event(c, 0, 1, 0);
		keybd_event(e, 0, 1, 0);
		keybd_event(enter, 0, 1, 0);
		counter++;
	}
}


