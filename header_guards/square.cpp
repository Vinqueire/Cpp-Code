#include "square.h"

int getSquareSides()
{
	return 4;
}

int getSquareParamiter(int sideLength)
{
	return sideLength * getSquareSides();
}