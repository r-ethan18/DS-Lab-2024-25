// Program to implement list ADT using classes

#include <iostream>

class list
{
private:
    int data[5];
    int current = 0;

public:
    int insertBeginning(int);
    int insertEnd(int);
    int insertPos(int, int);
    int deleteBeginning();
    int deleteEnd();
    int deletePos(int);
    int search(int);
    void display();
    int rotate(int);
};

int main()
{
    list listObj;
    int choice = 0;

    while (choice != 10)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1.Insert at the beginning\n";
        std::cout << "2.Insert at the end\n";
        std::cout << "3.Insert at a position\n";
        std::cout << "4.Delete element at the beginning\n";
        std::cout << "5.Delete element at the end\n";
        std::cout << "6.Delete element at a position\n";
        std::cout << "7.Search for an element\n";
        std::cout << "8.Display the list\n";
        std::cout << "9.Rotate the list\n";
        std::cout << "10.EXIT\n";

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int userData;
            int status;

            std::cout << "Enter the number to be inserted: ";
            std::cin >> userData;

            status = listObj.insertBeginning(userData);

            if (status == 1)
            {
                std::cout << "\n Element inserted at the beginning successfully!\n";
            }
            else
            {
                std::cout << "\n List is full! Element not inserted!\n";
            }
        }
        else if (choice == 2)
        {
            int userData;
            int status;

            std::cout << "Enter the number to be inserted: ";
            std::cin >> userData;

            status = listObj.insertEnd(userData);

            if (status == 1)
            {
                std::cout << "\n Element inserted at the end successfully!\n";
            }
            else
            {
                std::cout << "\n List is full! Element not inserted!\n";
            }
        }
        else if (choice == 3)
        {
            int userData;
            int userPos;
            int status;

            std::cout << "Enter the number to be inserted: ";
            std::cin >> userData;
            std::cout << "Enter the position to be inserted at: ";
            std::cin >> userPos;

            status = listObj.insertPos(userData, userPos);

            if (status == 1)
            {
                std::cout << "\n Element inserted at position " << userPos << " successfully!\n";
            }
            else if (status == -2)
            {
                std::cout << "\n List is full! Element not inserted!\n";
            }
            else if (status == -1)
            {
                std::cout << "\n Invalid Position entered!\n";
            }
        }
        else if (choice == 4)
        {
            int deletedElement = listObj.deleteBeginning();

            if (deletedElement == -1)
            {
                std::cout << "\n List is empty!\n";
            }
            else
            {
                std::cout << "\n Successfully deleted " << deletedElement << "\n";
            }
        }
        else if (choice == 5)
        {
            int deletedElement = listObj.deleteEnd();

            if (deletedElement == -1)
            {
                std::cout << "\n List is empty!\n";
            }
            else
            {
                std::cout << "\n Successfully deleted " << deletedElement << "\n";
            }
        }
        else if (choice == 6)
        {
            int userPos;

            std::cout << "Enter the position to be deleted: ";
            std::cin >> userPos;

            int deletedElement = listObj.deletePos(userPos);

            if (deletedElement == -1)
            {
                std::cout << "\n List is empty!\n";
            }
            else if (deletedElement == -2)
            {
                std::cout << "\n Invalid Position Entered!\n";
            }
            else
            {
                std::cout << "\n Successfully deleted " << deletedElement << "\n";
            }
        }
        else if (choice == 7)
        {
            int key;
            int position;

            std::cout << "Enter the element to be searched for: ";
            std::cin >> key;

            position = listObj.search(key);

            if (position == -1)
            {
                std::cout << "Element not found!";
            }
            else
            {
                std::cout << "Element found at index " << position << "\n";
            }
        }
        else if (choice == 8)
        {
            listObj.display();
        }
        else if (choice == 9)
        {
            int offset;
            int status;

            std::cout << "Enter the rotation offset: ";
            std::cin >> offset;

            status = listObj.rotate(offset);

            if (status == 1)
            {
                std::cout << "\n List rotation successful!\n";
            }
            else
            {
                std::cout << "\n List is empty!\n";
            }
        }
    }

    return 1;
}

// Function to insert the integer inData to the beginning of the list
int list::insertBeginning(int inData)
{
    if (current == 0)
    {
        data[0] = inData;
        current++;

        return 1;
    }
    else if (current == 5)
    {
        return -1;
    }
    else
    {
        for (int i = current; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = inData;
        current++;

        return 1;
    }
}

// Function to insert an element at the end of the list
int list::insertEnd(int inData)
{
    if (current == 5)
    {
        return -1;
    }
    else
    {
        data[current] = inData;
        current++;

        return 1;
    }
}

// Function to insert an element at a position
int list::insertPos(int inData, int inPos)
{
    if (inPos < 0 || inPos > current)
    {
        return -1;
    }
    else if (current == 5)
    {
        return -2;
    }
    else
    {
        for (int i = current; i > inPos; i--)
        {
            data[i] = data[i - 1];
        }
        data[inPos] = inData;
        current++;

        return 1;
    }
}

// Function to delete the element at the beginning of the list
int list::deleteBeginning()
{
    if (current == 0)
    {
        return -1;
    }
    else
    {
        int deleted = data[0];

        for (int i = 0; i < current; i++)
        {
            data[i] = data[i + 1];
        }
        current--;

        return deleted;
    }
}

// Function to delete the element at the end of the list
int list::deleteEnd()
{
    if (current == 0)
    {
        return -1;
    }
    else
    {
        int deleted = data[current - 1];
        current--;

        return deleted;
    }
}

// Function to delete the element at a position of the list
int list::deletePos(int inPos)
{
    if (current == 0)
    {
        return -1;
    }
    else if (inPos < 0 || inPos > current)
    {
        return -2;
    }
    else
    {
        int deleted = data[inPos];

        for (int i = inPos; i < current; i++)
        {
            data[i] = data[i + 1];
        }
        current--;

        return deleted;
    }
}

// Function to search for an element in the list
int list::search(int inKey)
{
    for (int i = 0; i < current; i++)
    {
        if (data[i] == inKey)
        {
            return i;
        }
    }

    return -1;
}

// Function to display the list
void list::display()
{
    if (current == 0)
    {
        std::cout << "List is Empty!\n";
    }
    else
    {
        std::cout << "\n";
        for (int i = 0; i < current; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to rotate the list
int list::rotate(int inOffset)
{
    if (current == 0)
    {
        return -1;
    }
    else if (current != 1)
    {
        for (int i = 0; i < inOffset; i++)
        {
            insertBeginning(deleteEnd());
        }
        return 1;
    }
    return 1;
}