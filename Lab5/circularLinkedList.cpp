// program to implement circular linked list

#include <iostream>

class CLL
{
    private:
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;
    int length;

    public:
    CLL();
    int insertBeg(int);
    int insertEnd(int);
    int insertPos(int, int);
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    int search(int);
    void display();
};

int main()
{
    CLL list;
    int choice = 0;

    while (choice != 9)
    {
        std::cout << "\nMenu: \n";
        std::cout << "1. Insert at Beginning\n";
        std::cout << "2. Insert at End\n";
        std::cout << "3. Insert at a position\n";
        std::cout << "4. Delete the element at the Beginning\n";
        std::cout << "5. Delete the element at the End\n";
        std::cout << "6. Delete the element at a Position\n";
        std::cout << "7. Search for an element\n";
        std::cout << "8. Display\n";
        std::cout << "9. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1)
        {
            int userData;

            std::cout << "Enter the element to be inserted: ";
            std::cin >> userData;

            if (list.insertBeg(userData) == 1)
            {
                std::cout << "Element successfully inserted!\n";
            }
            else
            {
                std::cout << "ERROR! Element not inserted!\n";
            }
        }
        else if (choice == 2)
        {
            int userData;

            std::cout << "Enter the element to be inserted: ";
            std::cin >> userData;

            if (list.insertEnd(userData) == 1)
            {
                std::cout << "Element successfully inserted!\n";
            }
            else
            {
                std::cout << "ERROR! Element not inserted!\n";
            }
        }
        else if (choice == 3)
        {
            int userData;
            int userPos;

            std::cout << "Enter the element to be inserted: ";
            std::cin >> userData;
            std::cout << "Enter the position to be inserted at: ";
            std::cin >> userPos;

            if (list.insertPos(userData, userPos) == 1)
            {
                std::cout << "Element successfully inserted!\n";
            }
            else
            {
                std::cout << "ERROR! Element not inserted!\n";
            }
        }
        else if (choice == 4)
        {
            int deleted = list.deleteBeg();

            if (deleted == -1)
            {
                std::cout << "List is empty!\n";
            }
            else
            {
                std::cout << "Deleted the element " << deleted << " successfully \n";
            }
        }
        else if (choice == 5)
        {
            int deleted = list.deleteEnd();

            if (deleted == -1)
            {
                std::cout << "List is empty!\n";
            }
            else
            {
                std::cout << "Deleted the element " << deleted << " successfully \n";
            }
        }
        else if (choice == 6)
        {
            int userPos;

            std::cout << "Enter the position: ";
            std::cin >> userPos;

            int deleted = list.deletePos(userPos);

            if (deleted == -1)
            {
                std::cout << "Invalid Position entered or the List is empty!\n";
            }
            else
            {
                std::cout << "Deleted the element " << deleted << " successfully \n";
            }
        }
        else if (choice == 7)
        {
            int userKey;

            std::cout << "Enter the search key: ";
            std::cin >> userKey;

            int found = list.search(userKey);

            if (found == -1)
            {
                std::cout << "Element not found!\n";
            }
            else
            {
                std::cout << "Element found at index: " << found << "\n";
            }
        }
        else if (choice == 8)
        {
            list.display();
        }
    }
}

CLL::CLL()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

// Function to insert an element at the beginning of a CLL
int CLL::insertBeg(int inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;
        
        length++;

        return 1;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;

        length++;

        return 1;
    }

    return -1;
}

// Function to insert an element at the end of the list
int CLL::insertEnd(int inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;
        
        length++;

        return 1;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        newNode->next = head;

        length++;

        return 1;
    }

    return -1;
}

// Function to insert an element at a position "inPos"
int CLL::insertPos(int inData, int inPos)
{
    if (inPos == 0)
    {
        insertBeg(inData);
        return 1;
    }
    else if (inPos == length)
    {
        insertEnd(inData);
        return 1;
    }
    else if (inPos > 0 && inPos < length)
    {
        struct node *temp = head;

        struct node *newNode = new struct node;
        newNode->data = inData;

        for (int i = 0; i < inPos-1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        return 1;
    }

    return -1;
}

// Function to delete an element at the beginning of the list
int CLL::deleteBeg()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        struct node *toDelete = head;   
        int deletedData = toDelete->data;

        if (toDelete->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = toDelete->next;
            tail->next = head;
        }

        delete toDelete;

        length--;

        return deletedData;
    }
}

// Function to delete the element at the end of the list
int CLL::deleteEnd()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        struct node *toDelete = tail;
        int deletedData = toDelete->data;

        if (length == 1)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            struct node *temp = head;

            while (temp->next->next != head)
            {
                temp = temp->next;
            }

            tail = temp;
            temp->next = head;
        }

        delete toDelete;

        length--;

        return deletedData;
    }
}

// Function to delete an element at the position "inPos"
int CLL::deletePos(int inPos)
{
    if (inPos == 0)
    {
        return(deleteBeg());
    }
    else if (inPos == length-1)
    {
        return(deleteEnd());
    }
    else if (inPos > 0 and inPos < length-1)
    {
        struct node *temp = head;

        for (int i = 0; i < inPos-1; i++)
        {
            temp = temp->next;
        }

        struct node *toDelete = temp->next;
        int deletedData = toDelete->data;

        temp->next = toDelete->next;

        delete toDelete;

        length--;

        return deletedData;
    }

    return -1;
}

// Function to search for an element "inKey" in the list
int CLL::search(int inKey)
{
    int foundPos = 0;

    struct node *temp = head;

    while(temp->next != head)
    {
        if (temp->data == inKey)
        {
            return foundPos;
        }

        temp = temp->next;
        foundPos++;
    }
    if (temp->data == inKey)
    {
        return foundPos;
    }

    return -1;
}

// Function to display the list
void CLL::display()
{
    if (head == NULL)
    {
        
        std::cout << "List is empty!\n";
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << temp->data << "\n";
    }
}