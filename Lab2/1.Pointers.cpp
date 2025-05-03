// Program to check for palindrome , armstrong and perfect number

#include <iostream>

int *palindrome(int *);
int *armstrong(int *);
int *perfect(int *);
int *reverseNum(int *);
int *power(int *, int *);
int *sumOfFactors(int *);
int *numOfDigits(int *);

int main()
{
    int *choice = new int;
    *choice = -1;

    while (*choice != 4)
    {
        std::cout << "\nMENU:\n1. Palindrome number\n2. Armstrong number\n3. Perfect Number\n4. Exit\n\n Enter Choice: ";
        std::cin >> *choice;

        if (*choice == 1)
        {
            int *number = new int;

            std::cout << "Enter a number: ";
            std::cin >> *number;
            std::cout << "\n";

            int *result = palindrome(number);

            if (*result == 1)
            {
                std::cout << *number << " is a Palindrome number\n";
            }
            else if (*result == 0)
            {
                std::cout << *number << " is not a Palindrome number\n";
            }

            delete number;
            delete result;
        }
        else if (*choice == 2)
        {
            int *number = new int;

            std::cout << "Enter a number: ";
            std::cin >> *number;
            std::cout << "\n";

            int *result = armstrong(number);

            if (*result == 1)
            {
                std::cout << *number << " is an Armstrong number\n";
            }
            else if (*result == 0)
            {
                std::cout << *number << " is not an Armstrong number\n";
            }

            delete number;
            delete result;
        }
        else if (*choice == 3)
        {
            int *number = new int;

            std::cout << "Enter a number: ";
            std::cin >> *number;
            std::cout << "\n";

            int* result = perfect(number);

            if (*result == 1)
            {
                std::cout << *number << " is a Perfect number\n";
            }
            else if (*result == 0)
            {
                std::cout << *number << " is not a Perfect number\n";
            }

            delete number;
            delete result;
        }
        else if (*choice == 4)
        {
            std::cout << "Exiting...\n";
        }
        else
        {
            std::cout << "Invalid choice!\n";
        }
    }

    delete choice;

    return 0;
}

// Function to find the reverse of a number 'inNum'
int *reverseNum(int *inNum)
{
    int *temp = new int;
    int *reversed = new int;

    *reversed = 0;
    *temp = *inNum;

    while (*temp > 0)
    {
        *reversed = (*reversed) * 10 + (*temp) % 10;
        *temp = *temp / 10;
    }

    delete temp;
    return reversed;
}

// Function to calculate the value of 'inNum' to the power 'pow'
int *power(int *inNum, int *pow)
{
    int *powered = new int;
    int *i = new int;

    *powered = 1;

    for (*i = 0; *i < *pow; (*i)++)
    {
        *powered = *powered * *inNum;
    }

    delete i;

    return powered;
}

// Function to calculate the sum of factors of a number 'inNum'
int *sumOfFactors(int *inNum)
{
    int *sum = new int;
    int *i = new int;

    *sum = 1;

    for (*i = 2; *i < *inNum; (*i)++)
    {
        if (*inNum % *i == 0)
        {
            *sum = *sum + *i;
        }
    }

    delete i;

    return sum;
}

// Function to calculate the number of digits in a number 'inNum'
int *numOfDigits(int *inNum)
{
    int *digitCount = new int;
    int *temp = new int;

    *temp = *inNum;
    *digitCount = 0;

    while (*temp > 0)
    {
        (*digitCount)++;
        *temp = *temp / 10;
    }

    delete temp;

    return digitCount;
}

// Function to check if the number 'inNum' is Palindrome or not, returns 1 if true
int *palindrome(int *inNum)
{
    int *returnNum = new int;
    int *reversedNum = reverseNum(inNum);

    if (*reversedNum == *inNum)
        *returnNum = 1;
    else
        *returnNum = 0;

    delete reversedNum;

    return returnNum;
}

// Function to check if the number 'inNum' is Armstrong or not, returns 1 if true
int *armstrong(int *inNum)
{
    int *returnNum = new int;
    int *countOfDigits = numOfDigits(inNum);
    int *temp = new int;
    int *sum = new int;
    int *digit = new int;
    int *poweredDigit;

    *sum = 0;
    *temp = *inNum;

    while (*temp != 0)
    {
        *digit = *temp % 10;
        poweredDigit = power(digit, countOfDigits);
        *sum = *sum + *(poweredDigit);

        *temp = *temp / 10;

        delete poweredDigit;
    }

    if (*sum == *inNum)
        *returnNum = 1;
    else
        *returnNum = 0;

    delete temp, sum, digit, countOfDigits;

    return returnNum;
}

// Function to check if the number 'inNum' is Perfect or not, returns 1 if true
int *perfect(int *inNum)
{
    int *returnNum = new int;
    int *factorSum = sumOfFactors(inNum);

    if (*factorSum == *inNum)
        *returnNum = 1;
    else
        *returnNum = 0;

    delete factorSum;
    
    return returnNum;
}