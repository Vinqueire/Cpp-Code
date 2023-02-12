#include <iostream>

int main()
{
	int userNum{};

	// Get input from the user
	std::cout << "Enter an intiger: ";
	std::cin >> userNum;
	
	// Output user's input *2
	std::cout << "Double: " << userNum << " is: " << userNum * 2 << std::endl;

	// Output user's input *3
	std::cout << "Triple: " << userNum << " is: " << userNum * 3 << std::endl;

	return 0;
}