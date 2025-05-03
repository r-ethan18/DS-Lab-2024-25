// Implementing a Max Heap Data Structure

#include <iostream>

class heap
{
private:
    int current;
    int array[20];
    int size = 20;

public:
    heap();
    int insert(int);
    int remove();
    int search(int);
    void display();
    void heapify(int, int);
};

int *sort(int *, int, int);

int main()
{
    heap MaxHeap;

    int choice = 0;

    while (choice != 6)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Display\n";
        std::cout << "4. Search\n";
        std::cout << "5. Sort\n";
        std::cout << "6. Exit\n";
        std::cout << "\nEnter your choice: ";

        std::cin >> choice;

        if (choice == 1)
        {
            int usrData;

            std::cout << "Enter the data to be inserted: ";
            std::cin >> usrData;

            int status = MaxHeap.insert(usrData);

            if (status == 0)
            {
                std::cout << "Element inserted successfully!\n";
            }
            else
            {
                std::cout << "Element not inserted! Heap may be full!\n";
            }
        }
        else if (choice == 2)
        {
            int removed = MaxHeap.remove();

            if (removed == -1)
            {
                std::cout << "Heap is Empty!\n";
            }
            else
            {
                std::cout << "Removed " << removed << " successfully\n";
            }
        }
        else if (choice == 3)
        {
            MaxHeap.display();
        }
        else if (choice == 4)
        {
            int usrKey;

            std::cout << "Enter the key to be searched for: ";
            std::cin >> usrKey;

            int foundAt = MaxHeap.search(usrKey);

            if (foundAt == -1)
            {
                std::cout << "Key not found in heap!\n";
            }
            else
            {
                std::cout << "Key found at index: " << foundAt << "\n";
            }
        }
        else if (choice == 5)
        {
            int arrSize;

            std::cout << "Enter the size of the array: ";
            std::cin >> arrSize;

            int arr[arrSize];

            std::cout << "Enter the elements of the array: \n";
            for (int i = 0; i < arrSize; i++)
            {
                std::cin >> arr[i];
            }

            int *ascArr = sort(arr, arrSize, 0);
            int *dscArr = sort(arr, arrSize, 1);

            std::cout << "The Array in Ascending order: \n";
            for (int i = 0; i < arrSize; i++)
            {
                std::cout << ascArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << "The Array in Descending order: \n";
            for (int i = 0; i < arrSize; i++)
            {
                std::cout << dscArr[i] << " ";
            }
            std::cout << "\n";
        }
    }
}

heap::heap()
{
    current = 0;
}

// Heapify Function, "opt" = 0 for Heapify Up, "opt" = 1 for Heapify Down
void heap::heapify(int start, int opt)
{
    if (opt == 0)
    {
        // Heapify Up
        /*
        Start from "current" index (last position)
            if its parent is less than it, swap, then recurse with start = start/2 (the position of the late parent[RIP])

            else do nothing (exiting the function)
        */

        int parent = start / 2;

        if (array[start] > array[parent] && start != 1 && start != 0)
        {
            int temp = array[start];
            array[start] = array[parent];
            array[parent] = temp;

            heapify(parent, 0);
        }
    }
    else if (opt == 1)
    {
        // Heapify Down
        /*
        Start from 1
            if any of its children ((start*2) or ((start*2)+1)) is greater, swap with the greatest;
            then recurse with start = (start*2) or ((start*2)+1) [whatever position was swapped]

            else do nothing (exiting the function)
        */

        int greatChild;

        if (array[start * 2] > array[(start * 2) + 1])
        {
            greatChild = start * 2;
        }
        else
        {
            greatChild = (start * 2) + 1;
        }

        if (array[start] < array[greatChild] && greatChild <= current)
        {
            int temp = array[start];
            array[start] = array[greatChild];
            array[greatChild] = temp;

            heapify(greatChild, 1);
        }
    }
}

// Function to insert an element "inData" into the heap
int heap::insert(int inData)
{
    if (current == 0)
    {
        array[1] = inData;
        current = 1;
        return 0;
    }
    else if (current == size - 1)
    {
        return 1;
    }
    else
    {
        current += 1;

        array[current] = inData;

        heapify(current, 0);

        return 0;
    }

    return 1;
}

// Function to remove the first element from the heap and return it
int heap::remove()
{
    if (current == 0)
    {
        return -1;
    }
    else if (current == 1)
    {
        current = 0;
        return (array[1]);
    }
    else
    {
        // remove first element, array[1] = array[current], decrement current, do heapify
        int returnElem = array[1];

        array[1] = array[current];
        current -= 1;

        heapify(1, 1);

        return (returnElem);
    }

    return -1;
}

// Function to search for an element in the heap, returns the index if found, else returns -1
int heap::search(int inKey)
{
    for (int i = 1; i <= current; i++)
    {
        if (array[i] == inKey)
        {
            return i;
        }
    }

    return -1;
}

// Function to sort an array using heap, "mode" = 0 for Ascending order, "mode" = 1 for Descending order
int *sort(int inArr[], int inSize, int mode)
{
    int *outArr = new int[inSize];

    heap temp;

    for (int i = 0; i < inSize; i++)
    {
        temp.insert(inArr[i]);
    }

    if (mode == 1)
    {
        for (int i = 0; i < inSize; i++)
        {
            outArr[i] = temp.remove();
        }
    }
    else if (mode == 0)
    {
        for (int i = inSize-1; i >= 0; i--)
        {
            outArr[i] = temp.remove();
        }
    }

    return outArr;
}

// Function to display the heap
void heap::display()
{
    if (current == 0)
    {
        std::cout << "Heap is Empty!\n";
    }
    else
    {
        for (int i = 1; i <= current; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
}