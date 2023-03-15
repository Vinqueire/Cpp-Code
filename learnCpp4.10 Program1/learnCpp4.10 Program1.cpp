#include <iostream>

int main()
{
	std::cout << "Enter a number 0 - 9" << std::endl;
	int x{};
	std::cin >> x;
	int ctr{ 0 };

	if (x == 0)
	{
		std::cout << "The number is not prime\n";
		return 0;
	}
	else if (x > 9)
	{
		std::cout << "You've entered the number out of range\n";
		return 0;
	}

	for (int i = 1; i <= x; ++i)
	{
		if (x % i == 0)
		{
			ctr++;
		}
	}

	if (x == 1 || ctr == 2)
	{
		std::cout << "The number is prime\n";
	}
	else 
		std::cout << "The number is not prime\n";

	return 0;
}