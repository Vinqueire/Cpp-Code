#include <iostream>
#include <cmath>

double getHeight();
double distance(int seconds);

int main()
{
	int seconds = 0;
	const double height{ getHeight() };
	double newHeight{height};

	while (height > 0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height: " 
			<< newHeight << std::endl;

		seconds++;
		newHeight = height - distance(seconds);
		if (newHeight <= 0)
		{
			std::cout << "At " << seconds << " the ball is on the ground."
				<< std::endl;
			break;
		}
	}
	return 0;
}

double getHeight()
{
	double height{};
	std::cout << "Enter the height of the tower in meters: ";
	std::cin >> height;

	return height;
}

double distance(int seconds)
{	
	double gravity = 9.8;
	double distance{ (gravity / 2) * pow(seconds, 2) };
	return distance;
}