#include <iostream>
#include <iomanip>

int main()
{
	int iValue{ 123 };
	float fValue{ 1.23f };
	double dValue{ 1.23 };
	long double ldValue{ 1.23 };

	std::cout << 5.0 << "\n";
	std::cout << 6.7f << "\n";
	std::cout << 9876543.21 << "\n";
	std::cout << std::endl;

	std::cout << 9.87654321f << "\n";
	std::cout << 987.654321f << "\n";
	std::cout << 987654.321f << "\n";
	std::cout << 9876543.21f << "\n";
	std::cout << 0.0000987654321f << "\n";
	std::cout << std::endl;

	std::cout << 3.33333333333333333333333333333333333333f << "\n";
	std::cout << 3.33333333333333333333333333333333333333 << "\n";

	std::cout << std::setprecision(16);
	std::cout << 3.33333333333333333333333333333333333333f << "\n";
	std::cout << 3.33333333333333333333333333333333333333 << "\n";

	return 0;
}