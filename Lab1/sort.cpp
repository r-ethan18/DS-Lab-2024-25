// Program to implement Bubble sort, Selection sort and Insertion Sort with a Selection menu
#include <iostream>

void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int);
void swap(int *, int, int);
void insert(int *, int, int);
void display(int *, int);

int main()
{
    int choice = 0;

    int length;

    std::cout << "Enter the length of the array: ";
    std::cin >> length;

    int array[length];

    std::cout << "Enter elements of the array: \n";
    for (int i = 0; i < length; i++)
    {
        std::cin >> array[i];
    }

    while (choice != 4)
    {
        std::cout << "\nMenu:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n\n Enter choice: ";
        std::cin >> choice;

        if (choice == 1)
            bubbleSort(array, length);
        else if (choice == 2)
            selectionSort(array, length);
        else if (choice == 3)
            insertionSort(array, length);
        else if (choice == 4)
        {
            std::cout << "Exiting...\n";
            break;
        }
        else
{
            std::cout << "Invalid choice!\n";
            continue;
        }
        std::cout << "\nSorted array: ";
        display(array, length);
    }

    return 0;
}

// Implementing bubble sort by "bubbling" the highest numbers towards the end
void bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
            {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

// Implementing selection sort by selecting the lowest number in the unsorted region and sending it back
void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr, i, smallest);
    }
}

// Implementing insertion sort by inserting numbers at their proper positions within the sorted region
void insertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                insert(arr, j, i);
            }
        }
    }
}

// function to swap the elements in pos1 and pos2 of arr with each other
void swap(int arr[], int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// function to insert an element from pos1 to pos2 in an array arr where pos1 < pos2
void insert(int arr[], int pos1, int pos2)
{
    for (int i = pos2; i > pos1; i--)
    {
        swap(arr, i, i - 1);
    }
}

// function to display the array "arr" of length "len"
void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}