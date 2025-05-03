// https://codeforces.com/contest/1767/problem/B

#include <iostream>

void sort (int*, int);

int main()
{
    int tests;
    std::cin >> tests;

    int solutions[tests];

    for (int i = 0 ; i < tests; i++)
    {
        int towers;
        int firstTower;

        std::cin >> towers;
        std::cin >> firstTower;

        int towerArray[towers-1]; // all towers other than the first tower

        for (int j = 0; j < towers - 1; j++)
        {
            std::cin >> towerArray[j];
        }

        sort(towerArray, towers-1);

        for (int j = 0; j < towers - 1; j++)
        {
            if (firstTower < towerArray[j])
            {
                if ((towerArray[j] - firstTower)%2 == 0)
                {
                    firstTower += (towerArray[j] - firstTower) / 2;
                }
                else
                {
                    firstTower += ((towerArray[j] - firstTower) / 2) + 1;
                }
            }
        }

        solutions[i] = firstTower;
    }

    for (int i = 0; i < tests; i++)
    {
        std::cout << solutions[i] << "\n";
    }
}

// Function to sort a list
void sort(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}