// Program to implement stack data structure using an array

#include <iostream>

using namespace std;

class stack
{
    private:
    char data[5];
    int top;

    public:
    stack();
    int push(char);
    char pop();
    char peek();
};

int main()
{
    stack arrStk;
    int choice = 0;

    while(choice != 4)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            char usrData;

            std::cout << "Enter the element to be inserted: ";
            std::cin >> usrData;

            if (arrStk.push(usrData) != 1)
            {
                std::cout << "Element successfully inserted!\n";
            }
            else
            {
                std::cout << "Stack full!\n";
            }
        }
        else if (choice == 2)
        {
            char returned = arrStk.pop();

            if (returned != '\0')
            {
                std::cout << "Popped " << returned << "\n";
            }
            else
            {
                std::cout << "Stack Empty!\n";
            }
        }
        else if (choice == 3)
        {
            char returned = arrStk.peek();

            if (returned != '\0')
            {
                std::cout << "Element at the top: " << returned << "\n";
            }
            else
            {
                std::cout << "Stack Empty!\n";
            }
        }
    }
}

stack::stack()
{
    top = -1;
}

// Function to push an element to the stack
int stack::push(char inData)
{
    if (top != 4)
    {
        data[top+1] = inData;
        top++;
        return 0;
    }
    return 1; 
}

// Function to pop the element at the top of the stack
char stack::pop()
{
    if (top != -1)
    {
        top -= 1;
        return data[top+1];
    }
    return '\0';
}

// Function to peek at the element at the top of the stack
char stack::peek()
{
    if (top != -1)
    {
        return data[top];
    }
    return '\0';
}