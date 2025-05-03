// Program to implement stack data structure using a Singly Linked List

#include <iostream>

using namespace std;

class stack
{
    private:
    struct node
    {
        char data;
        struct node *next;
    };

    struct node *head;

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
    head = NULL;
}

// Function to insert an element to the top of the stack.
int stack::push(char inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        return 0;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        return 0;
    }

    return 1;
}

// Function to pop the top element from the stack
char stack::pop()
{
    if (head == NULL)
    {
        return '\0';
    }
    else
    {
        struct node *oldHead = head;
        char popped = oldHead->data;

        head = oldHead->next;

        delete oldHead;

        return popped;
    }
}

// Function to peek the top element of the stack
char stack::peek()
{
    if (head == NULL)
    {
        return '\0';
    }
    else
    {
        return head->data;
    }
}