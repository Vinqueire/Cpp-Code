#include "square.h"
#include <iostream>

int main()
{
	std::cout << "Square has: " << getSquareSides() << " sides" << std::endl;
	std::cout << "A square of length 5 has a paramiter of: "
		<< getSquareParamiter(5);
	return 0;
}