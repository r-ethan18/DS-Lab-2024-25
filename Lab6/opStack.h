#include <iostream>

class charStack
{
private:
    struct node
    {
        char data;
        struct node *next;
    };
    struct node *head;
    int length;

public:
    charStack();
    int push(char);
    char pop();
    char peek();
};

charStack::charStack()
{
    head = NULL;
    length = 0;
}

// Function to insert an element to the top of the stack.
int charStack::push(char inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        length++;
        return 0;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        length++;
        return 0;
    }

    return -1;
}

// Function to pop the top element from the stack
char charStack::pop()
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
char charStack::peek()
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

class intStack
{
private:
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    int length;

public:
    intStack();
    int push(int);
    int pop();
};

intStack::intStack()
{
    head = NULL;
    length = 0;
}

// Function to insert an element to the top of the stack.
int intStack::push(int inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        length++;
        return 0;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        length++;
        return 0;
    }

    return -1;
}

// Function to pop the top element from the stack
int intStack::pop()
{
    struct node *oldHead = head;
    char popped = oldHead->data;

    head = oldHead->next;

    delete oldHead;

    return popped;
}