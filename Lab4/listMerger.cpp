#include "AscSLL.h"
#include <iostream>

int main()
{
    SLL list1;
    SLL list2;
    SLL list3;

    int choice = 0;

    while (choice != 5)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert List1\n";
        std::cout << "2. Insert List2\n";
        std::cout << "3. Merge to List3\n";
        std::cout << "4. Display\n";
        std::cout << "5. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int userData;

            std::cout << "Enter element to insert: ";
            std::cin >> userData;

            list1.insert(userData);
        }
        else if (choice == 2)
        {
            int userData;

            std::cout << "Enter element to insert: ";
            std::cin >> userData;

            list2.insert(userData);
        }
        else if (choice == 3)
        {
            list3.merge(list1, list2);
            std::cout << "Lists merged!\n";
        }
        else if (choice == 4)
        {
            std::cout << "\nList1: ";
            list1.display();
            std::cout << "List2: ";
            list2.display();
            std::cout << "List3: ";
            list3.display();
        }
    }
}