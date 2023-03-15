#include <iostream>

int enterInt();
bool isEqual(int a, int b);

int main()
{
	int x{ enterInt() };
	int y{ enterInt() };

	if (isEqual(x, y))
		std::cout << x << " and " << y << " are equal\n";
	else
		std::cout << x << " and " << y << " aren't equal\n";
}

int enterInt()
{
	int x{};
	std::cout << "Enter a number: ";
	std::cin >> x;

	return x;
}

bool isEqual(int a, int b)
{
	return (a == b);
}