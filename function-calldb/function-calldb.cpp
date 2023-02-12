#include <iostream>
#include <ctype.h>

void doubler(int userNum);

int main()
{
	int userNum{};
	
	// Figure out a way to find out if user inputed text or 0

	std::cout << "Input the number you want to double: ";
	std::cin >> userNum;

	std::cout << std::endl;

	doubler(userNum);

	return 0;
}

void doubler(int UserNum)
{
	if (std::cin)
	{
		if (UserNum > 0)
		{
			std::cout << UserNum << " Doubled is: " << UserNum * 2 << " :)\n";
		}
		else if (UserNum == 0)
		{
			std::cout << "How do you want me to double a 0 wtf\n";
		}
	}
	else if (!std::cin)
	{
		std::cout << "You think you are smart not typing a number in huh?\n";
	}
}