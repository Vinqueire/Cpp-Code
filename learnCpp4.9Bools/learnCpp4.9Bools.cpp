#include <iostream>

int main()
{
	bool b1{ true };
	bool b2{ false };

	b1 = false;
	bool b3{}; // Default initialization to false

	bool b4{ !true }; // This means false
	bool b5{ !false }; // This means true

	std::cout << true << std::endl;
	std::cout << false << std::endl;

	bool b6{ false };

	std::cout << std::boolalpha;

	std::cout << !b6 << std::endl;
	std::cout << b6 << std::endl;

	std::cout << std::noboolalpha;

	std::cout << !b6 << std::endl;
	std::cout << b6 << std::endl;


	// This is illegal and will produce an error bool a{ 4 };

	bool a1 = 4; // But this isn't (but it might produce a warning)	
	std::cout << a1 << std::endl; 

	bool a2 = 0;
	std::cout << a2 << std::endl;

	// To make a user be able to input bool values you need to use boolalpha
	bool a777{};
	std::cin >> std::boolalpha;
	std::cout << "Input either true or false: ";
	std::cin >> a777;
	std::cout << a777 << std::endl;
	std::cin >> std::noboolalpha;

	return 0;
}