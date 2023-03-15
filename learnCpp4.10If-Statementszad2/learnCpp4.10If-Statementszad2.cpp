#include <iostream>
int main()
{
    double height{};
    std::cin >> height;

    if (height > 140)
        std::cout << "Have fun!\n";
    else
        std::cout << "Sorry, you're too short.\n";
}