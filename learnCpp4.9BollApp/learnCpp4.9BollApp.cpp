#include <iostream>

int input();
bool areEqual(int a, int b);

int main()
{
	int x{input()};
	int y{input()};

	std::cout << std::boolalpha;
	std::cout << "is " << x << " and " << y << " equal? " << areEqual(x, y) << "\n";
}

bool areEqual(int a, int b)
{
	return (a == b);
}

int input()
{
	int x{};
	std::cout << "Input number: ";
	std::cin >> x;

	return x;
}