#include <iostream>

int add(int a, int b);

int main()
{
	std::cout << "Input a keyboard character: ";
	char x{};
	std::cin >> x;

	std::cout << "You've entered: " << x << std::endl;

	std::cout << "\"\"" << std::endl; // This prints ""
	std::cout << "\'\'" << std::endl; // This prints ''
	std::cout << "\\\\" << std::endl; // This prints \\

	std::cout << "6F in hex is char '\x6F'\n";

	int a{ 2 };
	int b{ 1 };

	std::cout << add(a, b) << '/n'; // This is bad because it uses a / instead of \ and it produces some bullshit

	return 0;
}

int add(int a, int b)
{
	return a + b;
}