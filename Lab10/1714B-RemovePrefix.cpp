// https://codeforces.com/problemset/problem/1714/B

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int indexOfNoMoreDuplicates(int[], int);

int main()
{
    int tests;
    std::cin >> tests;

    int solutions[tests];

    for (int test = 0; test < tests; test++)
    {
        int size;

        std::cin >> size;

        int numbers[size];

        for (int i = 0; i < size; i++)
        {
            std::cin >> numbers[i];
        }

        solutions[test] = indexOfNoMoreDuplicates(numbers, size);
    }

    for (int test = 0; test < tests; test++)
    {
        std::cout << solutions[test] << "\n";
    }
}

// returns the index after which there will be no more duplicates + 1
int indexOfNoMoreDuplicates(int inArr[], int inSize)
{
    // sets will hold unique values only
    set<int> check;
    
    if (inSize == 1)
    {
        return 0;
    }

    for (int i = inSize-1; i >= 0; i--)
    { 
        check.insert(inArr[i]);

        if (check.size() != inSize-i)
        {
            return (inSize - check.size());
        }
    }

    return (inSize - check.size());
}