#include <iostream>

void increment(int& a);

int main()
{
	int a = 5;
	int b = 8;
	int& ref = a;
	ref = b;
	// Don't do it like that, It will just make 'a' have the value of b and not chage what ref is referencing;
	// So basically a == 8, b == 8;

	// You also need to always assign a reference when you delcare it;
	// You can't do something like: int &;

	// You should just do it like this;

	int* reff = &a;
	reff = &b;
	// This will just make reff point to the value of a (5) and then reff will point to the value of b (8);
	// I mean technically it will point to 8 both times because of the "bug" we wrote before , but if it didn't exist that's how it would behave;


	increment(a);
	// So now this will produce a value of 9 since 
	/*
	int& ref = a;
	ref = b;
	made it so that a point to be at the start */

	std::cout << a << std::endl;

	return 0;
}

void increment(int& a)
{
	++a;
}