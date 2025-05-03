#include <iostream>
#include "opStack.h"

using namespace std;

string getInfix(string);
string convertInfix(string);
int evalPostfix(string);

bool isValidOperator(char);
bool isValidOperand(char);

int main()
{
    int choice = 0;
    string infixExp = "";
    string postfixExp = "";

    while (choice != 4)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Get Infix\n";
        std::cout << "2. Convert Infix\n";
        std::cout << "3. Evaluate Postfix\n";
        std::cout << "4. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            string usrExp;

            std::cout << "Enter the expression: ";
            std::cin >> usrExp;

            infixExp = getInfix(usrExp);

            if (infixExp == "INVALID")
            {
                std::cout << "Invalid Expression!\n";
                infixExp = "";
            }
            else
            {
                std::cout << "Expression saved!\n";
            }
        }
        else if (choice == 2)
        {
            if (infixExp == "")
            {
                std::cout << "No Infix Expression Loaded!\n";
            }
            else
            {
                postfixExp = convertInfix(infixExp);
            }
        }
        else if (choice == 3)
        {
            if (postfixExp == "")
            {
                std::cout << "No Postfix Expression Loaded!\n";
            }
            else
            {
                std::cout << "Result = " << evalPostfix(postfixExp) << "\n";
            }
        }
    }
}

// Function to check if the inputted Expression is valid.
std::string getInfix(std::string inExp)
{
    int length = inExp.length();

    if (inExp[0] == '+' || inExp[0] == '-')
    {
        inExp = "0" + inExp;
        length++;
    }
    else if (isValidOperator(inExp[0]))
    {
        return "INVALID";
    }
    if (inExp[length - 1] == '+' || inExp[length - 1] == '-')
    {
        inExp = inExp + "0";
        length++;
    }
    else if (isValidOperator(inExp[length - 1]))
    {
        return "INVALID";
    }

    if (length <= 2)
    {
        return "INVALID";
    }

    for (int i = 1; i < length - 1; i++)
    {
        if (!isValidOperand(inExp[i]) && !isValidOperator(inExp[i]))
        {
            return "INVALID";
        }
        else if (isValidOperator(inExp[i]))
        {
            if (!(isValidOperand(inExp[i - 1]) && isValidOperand(inExp[i + 1])))
            {
                return "INVALID";
            }
        }
        else if (isValidOperand(inExp[i]))
        {
            if (!(isValidOperator(inExp[i - 1]) && isValidOperator(inExp[i + 1])))
            {
                return "INVALID";
            }
        }
    }

    return inExp;
}

// Function to convert infix to postfix
std::string convertInfix(std::string inExp)
{
    charStack operatorStack;
    int length = inExp.length();
    std::string postFixExp = "";

    for (int i = 0; i < length; i++)
    {
        if (isValidOperand(inExp[i]))
        {
            postFixExp = postFixExp + inExp[i];
        }
        else if (isValidOperator(inExp[i]))
        {
            if (operatorStack.peek() != '\0')
            {
                if (inExp[i] == '+' || inExp[i] == '-')
                {
                    while (operatorStack.peek() != '\0')
                    {
                        postFixExp = postFixExp + operatorStack.pop();
                        while (operatorStack.peek() != '\0')
                        {
                            postFixExp = postFixExp + operatorStack.pop();
                        }
                    }
                    
                    operatorStack.push(inExp[i]);
                }
                else
                {
                    operatorStack.push(inExp[i]);
                }
            }
            else
            {
                operatorStack.push(inExp[i]);
            }
        }
    }

    while (operatorStack.peek() != '\0')
    {
        postFixExp = postFixExp + operatorStack.pop();
    }

    std::cout << postFixExp << "\n";

    return postFixExp;
}

// Function to evaluate the postfix expression and return the resulting value
int evalPostfix(std::string inExp)
{
    int length = inExp.length();
    intStack result;

    for (int i = 0; i < length; i++)
    {
        if (isValidOperand(inExp[i]))
        {
            result.push((int)inExp[i] - 48);
        }
        else
        {
            if (inExp[i] == '+')
            {
                int num1 = result.pop();
                int num2 = result.pop();

                result.push(num1 + num2);
            }
            else if (inExp[i] == '-')
            {
                int num1 = result.pop();
                int num2 = result.pop();

                result.push(num2 - num1);
            }
            else if (inExp[i] == '*')
            {
                int num1 = result.pop();
                int num2 = result.pop();

                result.push(num1 * num2);
            }
            else if (inExp[i] == '/')
            {
                int num1 = result.pop();
                int num2 = result.pop();

                result.push(num2 / num1);
            }
            else if (inExp[i] == '%')
            {
                int num1 = result.pop();
                int num2 = result.pop();

                result.push(num2 % num1);
            }
        }
    }

    return (result.pop());
}

// Function to check if the character is a valid operator (+, -, /, *, %, or =)
bool isValidOperator(char inChar)
{
    if (inChar == '+' || inChar == '-' || inChar == '*' || inChar == '/' || inChar == '%' || inChar == '=')
        return true;
    else
        return false;
}

// Function to check if the character is a valid operand (0-9)
bool isValidOperand(char inChar)
{
    if ((int)inChar >= 48 && (int)inChar <= 57)
        return true;
    else
        return false;
}