#include <iostream>
#include <iomanip>

int main()
{
	float f{ 123456789.0f }; // f has 10 significant digits
	std::cout << std::setprecision(9); // to shots 9 digits in floats
	std::cout << f << "\n";
	
	std::cout << std::setprecision(17);
	double d{ 0.1 };
	std::cout << d << "\n";

	double d1{ 1.0 };
	std::cout << d1 << "\n";

	double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
	std::cout << d2 << "\n";

	return 0;
}