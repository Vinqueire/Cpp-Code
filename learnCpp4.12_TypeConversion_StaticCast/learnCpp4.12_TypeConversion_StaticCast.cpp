#include <iostream>

void print(int x);

int main()
{
	char y{'a'};
	char x{ 97 };

	std::cout << y << " has value: " << static_cast<int>(x) << std::endl;

	// You can also use static_cast to convert unsigned intiger to signed ones

	unsigned int b{ 2u };
	std::cout << static_cast<int>(b) << std::endl;

	std::int8_t q{ 97 };
	std::cout << q << std::endl;
	std::cout << static_cast<int>(q) << std::endl;

	return 0;
}

void print(int x)
{
	std::cout << x << std::endl;
}