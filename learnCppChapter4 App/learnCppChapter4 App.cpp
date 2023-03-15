#include <iostream>

double getValue();
char getSign();
void result(double a, double b, char sign);

int main()
{
	const double a{ getValue() };
	const double d{ getValue() };
	const char sign{ getSign() };

	result(a, d, sign);

	return 0;
}

double getValue()
{
	double x{};
	std::cout << "Enter a double value: ";
	std::cin >> x;

	return x;
}

char getSign()
{
	char mod{};
	std::cout << "Enter one of the following: +, -, *, or /: ";
	std::cin >> mod;

	return mod;
}

void result(double a, double b, char sign)
{
	switch (sign)
	{
		case '*':
			std::cout << a << " * " << b << " is " << a * b;
			break;
		case '+':
			std::cout << a << " + " << b << " is " << a + b;
			break;
		case '-':
			std::cout << a << " - " << b << " is " << a - b;
			break;
		case '/':
			std::cout << a << " / " << b << " is " << a / b;
			break;
	}
	std::cout << std::endl;
}