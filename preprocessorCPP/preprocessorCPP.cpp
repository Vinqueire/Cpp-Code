#include <iostream>

#define PRINT_JOE

int main()
{

	#ifdef PRINT_JOE

	std::cout << "What's up Joe";

	#endif

	std::cout << "\n";

	#ifndef PRINT_BOB

	std::cout << "What's up Bob";

	#endif

	#if 0
		
	std::cout << "PLZ DON'T PRINT ME :C";

	#endif

	return 0;
}