// Program to implement Graph ADT using adjacency matrix.

#include <iostream>
#define SIZE 5

using namespace std;

class graph
{
private:
    int table[SIZE][SIZE];

public:
    graph();
    int insertEdge(int, int, int);
    int deleteEdge(int, int);
    int searchEdge(int, int);
    void display();
};

int main()
{
    graph AMGraph;
    int choice = 0;

    while (choice != 5)
    {
        cout << "\nMENU:\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search for an Edge\n";
        cout << "4. Display the Graph\n";
        cout << "5. Exit\n";
        cout << "\nEnter choice: ";

        cin >> choice;

        if (choice == 1)
        {
            int ver1, ver2, weight;

            cout << "Enter the origin vertex: ";
            cin >> ver1;
            cout << "Enter the destination vertex: ";
            cin >> ver2;

            cout << "Enter the weight of the edge: ";
            cin >> weight;

            int status = AMGraph.insertEdge(ver1, ver2, weight);

            if (status == -1)
                cout << "Edge already exists!\n";
            else if (status == -2)
                cout << "Invalid vertices!\n";
            else
                cout << "Edge inserted successfully!\n";
        }
        else if (choice == 2)
        {
            int ver1, ver2;

            cout << "Enter the origin vertex: ";
            cin >> ver1;
            cout << "Enter the destination vertex: ";
            cin >> ver2;

            int result = AMGraph.deleteEdge(ver1, ver2);

            if (result == -2)
                cout << "Invalid vertices!\n";
            else if (result == -1)
                cout << "No Edge exists here!\n";
            else
                cout << "Edge between " << ver1 << " and " << ver2 << " with weight " << result << "deleted";
        }
        else if (choice == 3)
        {
            int ver1, ver2;

            cout << "Enter the origin vertex: ";
            cin >> ver1;
            cout << "Enter the destination vertex: ";
            cin >> ver2;

            int result = AMGraph.searchEdge(ver1, ver2);

            if (result == -2)
                cout << "Invalid vertices!\n";
            else if (result == 0)
                cout << "No edge found!\n";
            else
                cout << "Edge with weight " << result << " exists between these vertices.\n";
        }
        else if (choice == 4)
        {
            AMGraph.display();
        }
    }

    return 0;
}

graph::graph()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            table[i][j] = 0;
        }
    }
}

// Function to insert an edge between the vertices 'inVer1' and 'inVer2', with weight 'inWeight'.
int graph::insertEdge(int inVer1, int inVer2, int inWeight)
{
    if (inVer1 >= SIZE || inVer2 >= SIZE || inVer1 < 0 || inVer2 < 0)
    {
        return -2;
    }

    if (searchEdge(inVer1, inVer2) > 0)
    {
        return -1;
    }

    table[inVer1][inVer2] = inWeight;

    return 0;
}

// Function to delete an edge between the vertices 'inVer1' and 'inVer2.
int graph::deleteEdge(int inVer1, int inVer2)
{
    if (inVer1 >= SIZE || inVer2 >= SIZE || inVer1 < 0 || inVer2 < 0)
    {
        return -2;
    }

    if (searchEdge(inVer1, inVer2) == 0)
    {
        return -1;
    }

    int returnData = table[inVer1][inVer2];
    table[inVer1][inVer2] = 0;

    return returnData;
}

// Function to check if an edge exists between 'inVer1' and 'inVer2'.
int graph::searchEdge(int inVer1, int inVer2)
{
    if (inVer1 >= SIZE || inVer2 >= SIZE || inVer1 < 0 || inVer2 < 0)
    {
        return -1;
    }

    if (table[inVer1][inVer2] > 0)
    {
        return table[inVer1][inVer2];
    }

    return 0;
}

// Function to display the Adjacency Matrix
void graph::display()
{
    cout << "   ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";
    }
    cout << "\n";
    cout << "   ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "-\t";
    }
    cout << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "| ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << table[i][j] << "\t";
        }
        cout << "\n";
    }
}