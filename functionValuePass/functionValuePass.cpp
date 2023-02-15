#include <iostream>

void doubler(int value)
{
	std::cout << value << " multiplied by 3 is: " << value * 3 << std::endl;
}

int inputer()
{
	std::cout << "Enter the value you want to double: ";

	int input{};

	std::cin >> input;
	
	std::cout << std::endl;

	return input;
}


int main()
{
	doubler(inputer());

	return 0;
}