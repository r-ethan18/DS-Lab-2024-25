#include <iostream>

class queue
{
private:
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;

public:
    queue();
    int enqueue(int);
    int dequeue();
    int peek();
};

queue::queue()
{
    head = NULL;
    tail = NULL;
}

// Function to qnueue an element into the queue
int queue::enqueue(int inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }

    return 0;
}

// Function to dequeue an element from the beginning of the queue
int queue::dequeue()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        int returnData = head->data;

        struct node *toDelete = head;
        head = head->next;

        delete toDelete;

        return returnData;
    }
}

// Function to display the element at the beginning of the queue
int queue::peek()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return head->data;
    }
}