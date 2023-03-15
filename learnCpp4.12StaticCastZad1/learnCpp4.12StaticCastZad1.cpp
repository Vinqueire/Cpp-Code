#include <iostream>
#include <cstdint>

int charToInt(char x);

int main()
{
	char user{};
	std::cout << "Enter a single character: ";
	std::cin >> user;
	

	std::cout << "You entered '" << user << "\', which has ASCII code "
		<< charToInt(user) << "\." << std::endl;

	return 0;
}

int charToInt(char x)
{
	return x;
}