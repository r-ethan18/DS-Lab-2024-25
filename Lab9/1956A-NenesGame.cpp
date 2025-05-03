#include <iostream>
#include <vector>

int main()
{
    int tests;
    std::cin >> tests;
    std::vector<std::vector<int>> solutions(tests);

    for (int i = 0; i < tests; i++)
    {
        int k;
        int q;

        std::cin >> k;
        std::cin >> q;

        std::vector<int> posArr(k);
        std::vector<int> grpArr(q);

        for (int j = 0; j < k; j++)
        {
            std::cin >> posArr[j];
        }
        for (int j = 0; j < q; j++)
        {
            std::cin >> grpArr[j];
        }

        for (int j = 0; j < q; j++)
        {
            while (1)
            {
                int count = 0;

                for (int l = 0; l < k; l++)
                {
                    if (posArr[l] <= grpArr[j])
                    {
                        count++;
                    }
                }

                grpArr[j] = grpArr[j] - count;

                if (count == 0)
                {
                    break;
                }
            }
        }
        solutions[i] = grpArr;
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
