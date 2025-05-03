// program to search for a key in an array using both Linear Search and Binary Search

#include <iostream>
#include "sort.h"

int linearSearch(int *, int, int);
int binarySearch(int *, int, int);

int main()
{
    int length, key, choice = 0;

    std::cout << "Enter the length of the array: ";
    std::cin >> length;

    int array[length];

    std::cout << "Enter elements of the array: \n";
    for (int i = 0; i < length; i++)
    {
        std::cin >> array[i];
    }

    while (choice != 3)
    {
        int found = -1;

        std::cout << "\nMenu:\n1. Linear Search\n2. Binary Search\n3. Exit\n\n Enter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Enter the search element: ";
            std::cin >> key;

            found = linearSearch(array, length, key);
        }
        else if (choice == 2)
        {
            std::cout << "Enter the search element: ";
            std::cin >> key;

            found = binarySearch(array, length, key);
        }
        else if (choice == 3)
        {
            std::cout << "Exiting...\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice!\n";
            continue;
        }

        if (found != -1)
            std::cout << "Element " << key << " is found at position " << found << "\n";
        else
            std::cout << key << " is not found in the array!\n";
    }

    return 0;
}

// function to linearly search for "key" in array "arr" and return index if found or return -1 if not found
int linearSearch(int arr[], int len, int key)
{
    int found = -1;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == key)
        {
            found = i;
            break;
        }
    }

    return found;
}

// function to do a binary search for "key" in array "arr" and return index if found or return -1 if not found
int binarySearch(int arr[], int len, int key)
{
    bubbleSort(arr, len);

    int start = 0;
    int end = len - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
    }

    return -1;
}