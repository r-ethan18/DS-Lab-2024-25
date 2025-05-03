// Program to implement an always sorted SLL, with merge functionality

#include <iostream>

class SLL
{
private:
    struct node
    {
        int data;
        struct node *next;
    };

    int length;
    struct node *head;
    struct node *tail;

public:
    SLL();
    struct node *getHead();
    int insert(int);
    void merge(SLL, SLL);
    void display();
};

int main()
{
    SLL mainList;
    int choice = 0;

    while (choice != 3)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Display\n";
        std::cout << "3. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int userData;

            std::cout << "Enter element to insert: ";
            std::cin >> userData;

            mainList.insert(userData);
        }
        else if (choice == 2)
        {
            mainList.display();
        }
    }
}

// Constructor
SLL::SLL()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

// Function which returns the address of the head of the list
SLL::node* SLL::getHead()
{
    return head;
}

// Function to insert the value inData in ascending order
int SLL::insert(int inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
        length++;
    }
    else
    {
        if (inData <= head->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else if (inData >= tail->data)
        {
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            struct node *temp = head;

            while (temp->next != NULL)
            {
                if (inData >= temp->data && inData <= temp->next->data)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    return 1;
}

// Function to merge 2 lists "inList1" and "inList2" into "outList"
void SLL::merge(SLL inList1, SLL inList2)
{
    struct node* head1 = inList1.getHead();
    struct node* head2 = inList2.getHead();

    struct node* temp = head1;

    while(temp != NULL)
    {
        insert(temp->data);
        temp = temp->next;
    }

    temp = head2;

    while(temp != NULL)
    {
        insert(temp->data);
        temp = temp->next;
    }
}

// Function to display the list
void SLL::display()
{
    if (head == NULL)
    {

        std::cout << "List is empty!\n";
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << temp->data << "\n";
    }
}