#include <iostream>

int getInput();

int main()
{
	int x{ getInput() };
	int y{ getInput() };

	if (x == y)
	{
		std::cout << x << " is equal " << y << std::endl;
		return 0;
	}

	(x > y) ? std::cout << x << " Is greater than " << y :
		std::cout << y << " Is greater than " << x;

	std::cout << std::endl;
	system("pause");

	return 0;
}

int getInput()
{
	int x{};
	std::cout << "Input your number: ";
	std::cin >> x;

	return x;
}

