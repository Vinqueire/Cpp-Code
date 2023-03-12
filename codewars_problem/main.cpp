#include <iostream>
#include <array>
#include <cstring>

size_t duplicateCount(const char* in);

int main()
{
    duplicateCount("aabbcde");
}

size_t duplicateCount(const char* in)
{
    // Base cases
    if (strcmp(in, " ") == 0 || strcmp(in, "") == 0)
    {
        return 0;
    }

    // Add each letter of the word to the array lowercased
    char arrayOfLetters[99];
    for (int i = 0, n = strlen(in); i < n; ++i)
    {
        arrayOfLetters[i] = tolower(in[i]);
    }
    int n = sizeof(arrayOfLetters);
    std::cout << arrayOfLetters << " Size is : " << n << std::endl;

    // Check if array contains duplicates and count how many and and the duplicate letters to a new array
    char arrayOfDuplicates[99];
    int letter = 0;
    int duplicateAmount = 0;
    int indexOfDuplicate = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        arrayOfDuplicates[i] = '`';
        for (int q = 0; q < n - 1; ++q)
        {
            if (arrayOfLetters[i] == arrayOfLetters[q])
            {
                letter++;
            }
        }
        if (letter >= 2)
        {
            duplicateAmount++;
            arrayOfDuplicates[indexOfDuplicate] = arrayOfLetters[i];
            indexOfDuplicate++;
        }
        letter = 0;
    }

    std::cout << " Amount of duplicates is: " << duplicateAmount << std::endl;
    std::cout << " Array of duplicates looks like this: " << arrayOfDuplicates << "It's size: " << sizeof(arrayOfDuplicates) << std::endl;


    std::string finalString = "";

    bool isInString = false;

    for (int i = 0; i < n; ++i)
    {
        for (int q = 0, s = finalString.length(); q < s; ++q)
        {
            if (isalnum(arrayOfDuplicates[i]) && arrayOfDuplicates[i] == finalString[q])
            {
                isInString = true;
            }
        }
        if (isInString == false)
        {
            finalString += arrayOfDuplicates[i];
        }
        isInString = false;
    }
    std::cout << "Final string is: " << finalString << "It's length: " << finalString.length() << std::endl;

    int finalCounter = 0;

    for (int i = 0, s = finalString.length() - 1; i < s; ++i)
    {
        if (finalString[i] != '`')
        {
            finalCounter += 1;
        }
    }

    std::cout << "Final counter is: " << finalCounter << std::endl;
    std::cout << std::endl;

    return finalCounter;
}