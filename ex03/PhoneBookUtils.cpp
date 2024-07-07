#include "PhoneBookUtils.h"
#include <cctype>

void printLine()
{
    std::cout << PRINT_LINE << std::endl;
}

int isFieldEmpty(std::string field)
{
    if (field.empty())
    {
        std::cout << EMPTY_VALUE << std::endl;
        std::cout << "> ";
        return (1);
    }
    return (0);
}

void phoneBookHeader()
{
    printLine();
    std::cout << std::setw(9) << "IDX";
    std::cout << "|" << std::setw(15) << "NAME";
    std::cout << "|" << std::setw(15) << "NICK_N.";
    std::cout << "|" << std::setw(15) << "PHONE_N.";
    std::cout << std::endl;
    printLine();
}

// if the return == 1, : not valid
int checkValidNumber(std::string str, int dbSize)
{
    int number = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i])){
            return (1);
        }
        number = std::stoi(str);
    }

    if (number && (number <= dbSize))
        return (0);
    else
    {
        return (1);
    }
}

std::string checkLength(std::string input)
{
    std::string ret = "";
    if (input.length() > 14)
    {
        for (int i = 0; i < 14; i++)
        {
            ret += input[i];
        }
        ret += ".";
    }
    else
        ret = input;
    return (ret);
}
