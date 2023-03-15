#include <iostream>
#include <cstdint>

int main()
{
	std::cout << "least 8 " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16 " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32 " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << "least 64 " << sizeof(std::int_least64_t) * 8 << " bits\n";
	std::cout << std::endl;
	std::cout << "fast 8 " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16 " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32 " << sizeof(std::int_fast32_t) * 8 << " bits\n";
	std::cout << "fast 64 " << sizeof(std::int_fast64_t) * 8 << " bits\n";
	std::cout << std::endl;

	std::uint_fast16_t randomFast{ 0 };
	randomFast--;

	std::cout << randomFast << std::endl;

	std::cout << sizeof(int) << std::endl;

	std::cout << sizeof(std::size_t) << std::endl;

}