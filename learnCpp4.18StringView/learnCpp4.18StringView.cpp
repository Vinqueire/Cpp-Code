#include <iostream>
#include <string>
#include <string_view>

int main()
{
	
	std::string_view sv{ "Hello world" };
	std::cout << sv << std::endl; // This is inputed using string view

	std::string s{ static_cast<std::string>(sv) };
	std::cout << s << std::endl; // This is inputed using string;

	using namespace std::literals;

	std::cout << "This is also a static_view String"sv << std::endl;
}
