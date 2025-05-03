#include <iostream>

class processList
{
private:
    struct node
    {
        int time;
        struct node *next;
    };
    struct node *head;
    struct node *tail;
    int length;

public:
    processList();
    int insertProc(int);
    int execute(int);
    void display();
};

processList::processList()
{
    head = NULL;
    tail = NULL;
}

// Function to insert an element at the end of the process list
int processList::insertProc(int inTime)
{
    struct node *newNode = new struct node;
    newNode->time = inTime;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;

        return 1;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        newNode->next = head;

        return 1;
    }

    return -1;
}

/* Function to delete an element at the beginning of the process list if the time = 0
 */
int processList::execute(int procTime)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        struct node *toExec = head;
        int modTime = toExec->time - procTime;

        if (modTime <= 0)
        {
            // permanently delete
            if (toExec->next == head)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = toExec->next;
                tail->next = head;
            }

            delete toExec;

            return -2;
        }
        else
        {
            // delete but insert at end
            insertProc(modTime);

            if (toExec->next == head)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = toExec->next;
                tail->next = head;
            }

            delete toExec;

            return -3;
        }
    }
}

// Function to display the list
void processList::display()
{
    if (head == NULL)
    {

        std::cout << "No processes!\n";
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            std::cout << temp->time << " -> ";
            temp = temp->next;
        }
        std::cout << temp->time << "\n";
    }
}