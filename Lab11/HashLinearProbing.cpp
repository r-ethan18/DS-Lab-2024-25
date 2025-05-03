// Program to implement a hash table with linear probing collision check

#include <iostream>
#define SIZE 20

class hashTable
{
    private:
    int table[SIZE];
    
    public:
    hashTable();
    int linProb(int);
    int hash(int);
    int insert(int);
    int search(int);
    int remove(int);
    void display();
};

int main()
{
    hashTable HT;
    int choice = 0;

    while(choice != 5)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Search\n";
        std::cout << "4. Display\n";
        std::cout << "5. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int usrData;

            std::cout << "Enter the element: ";
            std::cin >> usrData;

            int status = HT.insert(usrData);

            if (status != 1)
            {
                std::cout << "Inserted Successfully!\n";
            }
            else
            {
                std::cout << "Hash Table Full!\n";
            }
        }
        else if (choice == 2)
        {
            int usrData;

            std::cout << "Enter the element to be deleted: ";
            std::cin >> usrData;

            int deleted  = HT.remove(usrData);

            if (deleted != -1)
            {
                std::cout << deleted << " was deleted successfully!\n";
            }
            else
            {
                std::cout << "Element was not found!\n";
            }
        }
        else if (choice == 3)
        {
            int usrData;

            std::cout << "Enter the element to be searched for: ";
            std::cin >> usrData;

            int foundAt  = HT.search(usrData);

            if (foundAt != -1)
            {
                std::cout << "Element was found at " << foundAt << " \n";
            }
            else
            {
                std::cout << "Element was not found in the table!\n";
            }
        }
        else if (choice == 4)
        {
            HT.display();
        }
        else if (choice == 5)
        {
            std::cout << "Exiting...\n";
        }
        else
        {
            std::cout << "Invalid choice!\n";
        }
    }
}

hashTable::hashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
    }
}

// Function to find an empty position from an initial position "inPos" using linear probing, if not found returns -1
int hashTable::linProb(int inPos)
{
    for (int i = inPos; i < (SIZE + inPos); i++)
    {
        if (table[i%SIZE] == -1)
        {
            return (i%SIZE);
        }
    }

    return -1;
}

// Function to get the hash of a value
int hashTable::hash(int inNum)
{
    return (inNum % SIZE);
}

// Function to insert an element into the hash table
int hashTable::insert(int inNum)
{
    int hashVal = hash(inNum);

    if (table[hashVal] == -1)
    {
        table[hashVal] = inNum;
        return 0;
    }
    
    int freePos = linProb(hashVal);

    if (freePos == -1)
    {
        return 1;
    }
    else
    {
        table[freePos] = inNum;
        return 0;
    }
}

// Function that searches for an element and returns its index, else returns -1
int hashTable::search(int inData)
{
    int searchHash = hash(inData);

    if (table[searchHash] == inData)
    {
        return searchHash;
    }
    else
    {
        for (int i = searchHash; i < SIZE + searchHash; i++)
        {
            if (table[i%SIZE] == inData)
            {
                return i;
            }
        }
    }

    return -1;
}

// Function to remove an element from the hash table
int hashTable::remove(int inRemData)
{
    int foundAt = search(inRemData);

    if (foundAt != -1)
    {
        int returnData = table[foundAt];
        table[foundAt] = -1;

        return returnData;
    }

    return -1;
}

// Function to display the hashtable
void hashTable::display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
        {
            std::cout << "_ ";
        }
        else
        {
            std::cout << table[i] << " ";
        }
    }
    std::cout << "\n";
}