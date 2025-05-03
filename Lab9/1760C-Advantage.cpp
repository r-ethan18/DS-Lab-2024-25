// https://codeforces.com/problemset/problem/1760/C

#include <iostream>
#include <vector>

int firstLargest(std::vector<int>);
int secondLargest(std::vector<int>, int);

int main()
{
    int tests;
    std::cin >> tests;

    // vector of vectors
    std::vector<std::vector<int>> solutions(tests);

    for (int i = 0; i < tests; i++)
    {
        int len;
        std::cin >> len;

        std::vector<int> arr(len);
        std::vector<int> advantages(len);

        for (int j = 0; j < len; j++)
        {
            std::cin >> arr[j];
        }

        int fLargest = firstLargest(arr);
        int sLargest = secondLargest(arr, fLargest);

        // std::cout << fLargest << " " << sLargest << "\n";

        for (int j = 0; j < len; j++)
        {
            if (j == fLargest)
            {
                advantages[j] = arr[j] - arr[sLargest];
            }
            else
            {
                advantages[j] = arr[j] - arr[fLargest];
            }
        }

        solutions[i] = advantages;
    }

    for (int i = 0; i < tests; i++)
    {
        for (int j = 0; j < solutions[i].size(); j++)
        {
            std::cout << solutions[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// returns the index of the first largest element in the array
int firstLargest(std::vector<int> inArr)
{
    int inLen = inArr.size();

    int largest  = 0;
    for (int i = 0; i < inLen; i++)
    {
        if (inArr[i] > inArr[largest])
        {
            largest = i;
        }
    }

    return largest;
}

// returns the index of the second largest element in the array
int secondLargest(std::vector<int> inArr, int firstLargestPos)
{
    int inLen = inArr.size();

    int largestNo = 0;
    int largest = 0;

    for (int i = 0; i < inLen; i++)
    {
        if (inArr[i] > largestNo && i != firstLargestPos)
        {
            largest = i;
            largestNo = inArr[i];
        }
    }

    return largest;
}