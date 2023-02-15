#include <iostream>

void print()
{
	std::cout << "This is some random sample text" << std::endl;

	return;

	std::cout << "This is unreachable" << std::endl;
}

int main()
{
	print();

	return 0;
}