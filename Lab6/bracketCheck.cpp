// Program to check if brackets are balanced

#include <iostream>
#include "opStack.h"

bool checkBrackets(std::string);

int main()
{
    int choice = 0;

    while (choice != 2)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Check brackets\n";
        std::cout << "2. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string brackets;

            std::cout << "Enter the string: ";
            std::cin >> brackets;

            if (checkBrackets(brackets))
            {
                std::cout << "Brackets are balanced!\n";
            }
            else
            {
                std::cout << "Brackets are not balanced!\n";
            }
        }
    }
}

bool checkBrackets(std::string inStr)
{
    int len = inStr.length();
    charStack stk;

    for (int i = 0; i < len; i++)
    {
        if (inStr[i] == '(')
        {
            stk.push('(');
        }
        else if (inStr[i] == ')')
        {
            if (stk.peek() != '\0')
            {
                stk.pop();
            }
            else
            {
                stk.push(')');
            }
        }
    }

    if (stk.peek() == '\0')
        return true;
    else
        return false;
}