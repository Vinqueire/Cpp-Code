#include "additional.h"
#include <iostream>

int multiply(int a, int b);

int main()
{
	Log("Multiply");
	std::cout << multiply(3, 5) << std::endl;
	std::cin.get();
}

int multiply(int a, int b)
{
	return a * b;
}