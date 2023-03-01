#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int amount{};
    std::ifstream pushups;

    pushups.open("pushups.txt", std::ios::app);

    pushups >> amount;

    std::cout << "Max 22 non weighted pushups in row\n";

    std::cout << "You've done: " << amount << 
        " Non weigted pushups so far\n";



    int amountWeighted{};
    std::ifstream weighted;

    weighted.open("weighted.txt", std::ios::app);

    weighted >> amountWeighted;

    std::cout << "You've done: " << amountWeighted <<
        " Weighted pushups so far\n";

    std::cout << std::endl;

    std::cout << "Type 0 to add non weighted / Type 1 to add weighted : ";

    bool type{};

    std::cin >> type;

    int add{};

    if (!type)
    {
        std::cout << "Enter the amount you want to add: ";
        std::cin >> add;
        std::cout << std::endl;

        int total = amount + add;
        pushups.close();

        std::ofstream pushupsWrite;
        pushupsWrite.open("pushups.txt", std::ios::out);

        pushupsWrite << total;
        
        pushupsWrite.close();
    }
    else
    {
        std::cout << "Enter the amount you want to add: ";
        std::cin >> add;
        std::cout << std::endl;

        int total = amountWeighted + add;

        weighted.close();

        std::ofstream weighedWrite;
        weighedWrite.open("weighted.txt", std::ios::out);

        weighedWrite << total;    

        weighedWrite.close();
    }

    pushups.open("pushups.txt", std::ios::app);

    pushups >> amount;

    std::cout << "You've done: " << amount <<
        " Non weighted pushups so far\n";


    weighted.open("weighted.txt", std::ios::app);

    weighted >> amountWeighted;

    std::cout << "You've done: " << amountWeighted <<
        " Weighted pushups so far\n";

    std::cout << std::endl;

    pushups.close();
    weighted.close();

    system("pause");
    return 0;
}
