#include <iostream>
#include "processListing.h"

int main()
{
    processList list;
    int choice = 0;

    int shareTime;
    std::cout << "Enter the shared process time: ";
    std::cin >> shareTime;

    while (choice != 4)
    {
        std::cout << "\nMenu: \n";
        std::cout << "1. Insert Process\n";
        std::cout << "2. Execute Process\n";
        std::cout << "3. Display\n";
        std::cout << "4. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1)
        {
            int procTime;

            std::cout << "Enter the process time: ";
            std::cin >> procTime;

            if (list.insertProc(procTime) == 1)
            {
                std::cout << "Process successfully inserted\n";
                list.display();
            }
            else
            {
                std::cout << "Process not inserted!\n";
            }
        }
        else if (choice == 2)
        {
            int status = list.execute(shareTime);
            if (status == -2)
            {
                std::cout << "Process Ended!\n";
                list.display();
            }
            else if (status == -1)
            {
                std::cout << "All processes Ended already!\n";
            }
            else
            {
                std::cout << "Process re-Inserted!\n";
                list.display();
            }
        }
        else if (choice == 3)
        {
            list.display();
        }
    }
}