#include <iostream>

#include "io.h"

int readNumber()
{
	std::cout << "Input your number: ";
	int num{};
	std::cin >> num;

	return num;
}

void writeAnswer(int num)
{
	std::cout << "The two intigers added equal: " << num << std::endl;
}