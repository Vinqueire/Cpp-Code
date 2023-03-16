#include <iostream>

int main()
{
    std::cout << "How old are you?\n";

    int age{};
    constexpr int legalAge{ 16 };
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas [";

    if (age >= legalAge)
        std::cout << 'x';
    else
        std::cout << ' ';

    std::cout << "]" << std::endl;

    return 0;
}