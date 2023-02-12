#include <iostream>

void functionB()
{
	std::cout << "This shit is printed from function B\n";

	std::cout << std::endl;
}

void functionA()
{
	std::cout << "This is printed from function A\n";
	functionB();
}

int main()
{
	int EX{};

	std::cout << "This shit is printed inside main\n";
	std::cout << "Type in how many times you want to call function A, which"
		" will call function B: ";
	std::cin >> EX;

	std::cout << std::endl;



	for (int i = 0; i < EX; ++i)
	{
		functionA();
	}

	return 0;
}