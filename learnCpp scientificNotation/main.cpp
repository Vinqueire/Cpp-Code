#include <iostream>

int main()
{
	// Zrób dział z scientific notation dopoki nie zrozumiesz go w 100%
	int32_t test1{ 42030 };
	std::cout << 4.203e4 << "\t4 significant numbers\n";

	double test2{ 0.0078900 };
	std::cout << 7.8900e-3 << "\t5 significant numbers\n";

	double test3{ 600.410 };
	std::cout << 6.00410e2 << "\t6 significant numbers\n";


	double zad1{ 34.50 };
	std::cout << 3.450e1 << "\t4 significant numbers\n";

	double zad2{ 0.004000 };
	std::cout << 4.000e-3 << "\t4 significant numbers\n";

	double zad3{ 123.005 };
	std::cout << 1.23005e2 << "\t6 significant numbers\n";

	int32_t zad4{ 146000 };
	std::cout << 1.46e5 << "\t3 significant numbers\n";

	double zad5{ 146000.001 };
	std::cout << 1.46000001e5 << "\t9 significant numbers\n";

	double zad6{ 0.0000000008 };
	std::cout << 8e-10 << "\t1 significant number\n";

	double zad7{ 34500.0 };
	std::cout << 3.45000e4 << "\t6 significant numbers\n";
}