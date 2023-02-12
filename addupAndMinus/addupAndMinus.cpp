#include <iostream>

int main()
{
	int firstNum{};
	int secondNum{};

	std::cout << "Enter an intiger: ";
	std::cin >> firstNum;

	std::cout << "Enter another intiger: ";
	std::cin >> secondNum;

	std::cout << firstNum << " + " << secondNum << " is "
		<< firstNum + secondNum << ".\n" ;

	std::cout << firstNum << " - " << secondNum << " is "
		<< firstNum - secondNum << ".\n";

	return 0;
}