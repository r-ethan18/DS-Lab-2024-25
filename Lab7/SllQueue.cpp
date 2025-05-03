// Program to implement a queue using SLL

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
    void display();
};

int main()
{
    queue qObj;
    int choice = 0;

    while (choice != 4)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Exit\n";
        std::cout << "\nEnter choice: ";

        std::cin >> choice;

        if (choice == 1)
        {
            int enqData;

            std::cout << "Enter the data to be inserted: ";
            std::cin >> enqData;

            int status = qObj.enqueue(enqData);

            if (status = 0)
            {
                std::cout << enqData << " inserted successfully!\n";
            }

            qObj.display();
        }
        else if (choice == 2)
        {
            int dequeued = qObj.dequeue();

            if (dequeued == -1)
            {
                std::cout << "Queue is empty!\n";
            }
            else
            {
                std::cout << dequeued << " dequeued successfully!\n";
                qObj.display();
            }
        }
        else if (choice == 3)
        {
            int peeked = qObj.peek();

            if (peeked == -1)
            {
                std::cout << "Queue is empty!\n";
            }
            else
            {
                std::cout << peeked << " is at the Beginning of the queue!\n";
            }
        }
        else if (choice == 4)
        {
            std::cout << "Exiting...\n";
        }
        else
        {
            std::cout << "INVALID CHOICE!\n";
        }
    }
}

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

// Function to display the queue
void queue::display()
{
    if (head == NULL)
    {
        std::cout << "Queue is empty!\n";
    }
    else
    {
        struct node *temp = head;

        while (temp->next != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << temp->data << "\n";
    }
}