#include <iostream>

void printer()
{
	std::cout << "And this is printed via a printer\n";
	std::cout << ":)\n";

}

int main()
{
	std::cout << "This shit is printed in main\n" << std::endl;
	printer();
	printer();
	printer();
	std::cout << std::endl;
	std::cout << "This isn't EXDE\n";

	return 0;
}