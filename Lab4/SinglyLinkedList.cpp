// program to implement singly linked list in C++

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
    int insertBeg(int);
    int insertEnd(int);
    int insertPos(int, int);
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    int search(int);
    void display();
    void reverse();
    void reverseLink();
};

SLL::SLL()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

int main()
{
    SLL list;
    int choice = 0;

    while (choice != 11)
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
        std::cout << "9. Display in Reverse\n";
        std::cout << "10. Reverse Links\n";
        std::cout << "11. Exit\n";

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
        else if (choice == 9)
        {

            list.reverse();
        }
        else if (choice == 10)
        {
            list.reverseLink();
        }
    }
}

// Function to insert an element "inData" to the beginning of the list
int SLL::insertBeg(int inData)
{
    if (head == NULL)
    {
        struct node *newNode = new struct node;
        newNode->data = inData;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
        length++;
        return 1;
    }
    else
    {
        struct node *newNode = new struct node;
        newNode->data = inData;
        newNode->next = head;
        head = newNode;
        length++;
        return 1;
    }

    return -1;
}

// Function to insert element "inData" at the end
int SLL::insertEnd(int inData)
{
    if (head == NULL)
    {
        insertBeg(inData);
        return 1;
    }
    else
    {
        struct node *newNode = new struct node;
        newNode->data = inData;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
        length++;
        return 1;
    }

    return -1;
}

// Function to insert the element "inData" at position "inPos" of the list
int SLL::insertPos(int inData, int inPos)
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

        for (int i = 1; i < inPos; i++)
        {
            temp = temp->next;
        }

        newNode->data = inData;
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return 1;
    }

    return -1;
}

// Function to delete the element at the beginning of the list
int SLL::deleteBeg()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        struct node *temp = head;
        int returnData = temp->data;
        head = temp->next;
        delete temp;
        length--;
        return returnData;
    }
}

// Function to delete the element at the end of the list
int SLL::deleteEnd()
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head == tail)
    {
        int returnData = deleteBeg();
        return returnData;
    }
    else
    {
        int returnData = tail->data;
        struct node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
        delete temp->next;

        length--;

        return returnData;
    }
}

// Function to delete the element at position "inPos" of the list
int SLL::deletePos(int inPos)
{
    if (inPos == 0)
    {
        return (deleteBeg());
    }
    else if (inPos == length - 1)
    {
        return (deleteEnd());
    }
    else if (inPos > 0 && inPos < length - 1)
    {
        struct node *temp = head;

        for (int i = 0; i < inPos - 1; i++)
        {
            temp = temp->next;
        }

        int returnData = temp->next->data;
        struct node *deletePosPtr = temp->next;
        temp->next = temp->next->next;

        delete deletePosPtr;

        length--;
        return returnData;
    }

    return -1;
}

// Function to search for the value "inKey" in the list
int SLL::search(int inKey)
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

// Function to display the list normally
void SLL::display()
{
    std::cout << "\nLength = " << length << "\n";

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

// Function to display the list in reverse
void SLL::reverse()
{
    if (head == NULL)
    {
        std::cout << "List is empty!\n";
    }
    else
    {
        std::string output = "";
        struct node *temp = head;

        output = std::to_string(temp->data);
        temp = temp->next;

        while (temp != NULL)
        {
            output = std::to_string(temp->data) + " -> " + output;
            temp = temp->next;
        }

        std::cout << output << "\n";
    }
}

// Function to reverse the links of the list
void SLL::reverseLink()
{
    struct node *newHead = tail;
    struct node *newTail = head;

    for (int limit = length - 1; limit > 0; limit--)
    {
        struct node *swap1 = head;
        struct node *swap2 = head;

        for (int i = 0; i < limit; i++)
        {
            swap1 = swap1->next;
        }
        for (int i = 0; i < limit - 1; i++)
        {
            swap2 = swap2->next;
        }

        swap1->next = swap2;
        swap2->next = NULL;
    }

    head = newHead;
    tail = newTail;
}