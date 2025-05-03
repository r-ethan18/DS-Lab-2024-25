// Program to implement a doubly linked list with a tail

#include <iostream>

class DLL
{
private:
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    };

    struct node *head;
    struct node *tail;
    int length;

public:
    DLL();
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
    DLL list;
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

            int foundAt = list.search(userKey);

            if (foundAt == -1)
            {
                std::cout << "Search element not found in the list!\n";
            }
            else
            {
                std::cout << "Search element found at position " << foundAt << " \n";
            }
        }
        else if (choice == 8)
        {
            list.display();
        }
    }
}

DLL::DLL()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

// Function to insert the element at the beginning of the list
int DLL::insertBeg(int inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;

        head = newNode;
        tail = newNode;
        length++;

        return 1;
    }
    else
    {
        newNode->next = head;
        newNode->prev = NULL;
        newNode->next->prev = newNode;

        head = newNode;
        length++;

        return 1;
    }
}

// Function to insert the element at the end of the list
int DLL::insertEnd(int inData)
{
    struct node *newNode = new struct node;
    newNode->data = inData;

    if (head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;

        head = newNode;
        tail = newNode;
        length++;

        return 1;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;

        tail = newNode;
        length++;

        return 1;
    }
}

// Function to insert an element at a position
int DLL::insertPos(int inData, int inPos)
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
        struct node *newNode = new struct node;
        newNode->data = inData;

        struct node *temp = head;
        struct node *tempNext;

        for (int i = 0; i < inPos - 1; i++)
        {
            temp = temp->next;
        }

        tempNext = temp->next;
        temp->next = newNode;
        newNode->next = tempNext;

        length++;
        return 1;
    }

    return -1;
}

// Function to delete the element at the beginning of the list
int DLL::deleteBeg()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        struct node *deleted = head;
        int deletedData = deleted->data;

        if (head->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }

        delete deleted;

        length--;
        return deletedData;
    }
}

// Function to delete the end of the list
int DLL::deleteEnd()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        struct node *deleted = tail;
        int deletedData = deleted->data;

        if (tail->prev != NULL)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            tail = NULL;
            head = NULL;
        }

        delete deleted;

        length--;
        return deletedData;
    }
}

// Function to delete an element at a position
int DLL::deletePos (int inPos)
{
    if (inPos == 0)
    {
        return(deleteBeg());
    }
    else if (inPos == length-1)
    {
        return(deleteEnd());
    }
    else
    {
        struct node *temp = head;

        for (int i = 0; i < inPos; i++)
        {
            temp = temp->next;
        } 
        int deletedElem = temp->data;
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;

        length--;
        return (deletedElem);
    }
    return -1;
}

// Function to search for the value "inKey" in the list
int DLL::search(int inKey)
{
    int foundPos = -1;
    int i = 0;

    struct node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == inKey)
        {
            foundPos = i;
            break;
        }
        else
        {
            i++;
            temp = temp->next;
        }
    }

    return foundPos;
}

// Function to display the list
void DLL::display()
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