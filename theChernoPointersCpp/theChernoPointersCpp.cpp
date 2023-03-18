#include <iostream>

#define log(x) std::cout << x << std::endl;

int main()
{
	int var{ 8 };
	int* ptr = &var;

	int** buffer = &ptr;
	int*** ptrBuf = &buffer;
	
	std::cout << ***ptrBuf << std::endl;

	system("pause");

	// This gave me insane joy 
	return 0;
}