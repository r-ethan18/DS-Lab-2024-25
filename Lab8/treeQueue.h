#include <iostream>

struct treeNode
{
    char data;
    struct node* left;
    struct node* right;
};

class queue
{
private:
    struct node
    {
        struct treeNode* data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;

public:
    queue();
    int enqueue(treeNode*);
    treeNode* dequeue();
    treeNode* peek();
};

queue::queue()
{
    head = NULL;
    tail = NULL;
}

// Function to qnueue an element into the queue
int queue::enqueue(treeNode* inData)
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
treeNode* queue::dequeue()
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        treeNode* returnData = head->data;

        struct node *toDelete = head;
        head = head->next;

        delete toDelete;

        return returnData;
    }
}

// Function to display the element at the beginning of the queue
treeNode* queue::peek()
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        return head->data;
    }
}