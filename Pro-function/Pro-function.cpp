#include <iostream>

void funB()
{
	std::cout <<"This is in B\n";
}

void funA()
{
	std::cout << "This is in A\n";
	funB();
}

int main()
{
	std::cout << "This shit is in main\n";
	std::cout << std::endl;
	funA();
	funB();
	std::cout << std::endl;
	std::cout << "And this is again in main leattt\n";

	return 0;
}