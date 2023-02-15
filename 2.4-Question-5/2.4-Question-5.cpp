#include <iostream>

int doubleNumber(int x)
{
	return x * 2;
}


int main()
{
	std::cout << "Type in the number you want to double: ";

	int number{};

	std::cin >> number;

	std::cout << std::endl;

	std::cout << number << " Doubled is: " << doubleNumber(number) << std::endl;
	

}