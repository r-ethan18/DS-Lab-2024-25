// Program to implement graph ADT using Adjacency List

#include <iostream>
#define SIZE 5

using namespace std;

class graphList
{
private:
    struct vertex
    {
        int label;
        int weight;
        vertex *next;
    };

    vertex *list[SIZE];

public:
    graphList();
    int insertEdge(int, int, int);
    int deleteEdge(int, int);
    int searchEdge(int, int);
    void display();
};

int main()
{
    graphList GL;
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

            int status = GL.insertEdge(ver1, ver2, weight);

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

            int result = GL.deleteEdge(ver1, ver2);

            if (result == -2)
                cout << "Invalid vertices!\n";
            else if (result == -1)
                cout << "No Edge exists here!\n";
            else
                cout << "Edge between " << ver1 << " and " << ver2 << " with weight " << result << " deleted";
        }
        else if (choice == 3)
        {
            int ver1, ver2;

            cout << "Enter the origin vertex: ";
            cin >> ver1;
            cout << "Enter the destination vertex: ";
            cin >> ver2;

            int result = GL.searchEdge(ver1, ver2);

            if (result == -1)
                cout << "Invalid vertices!\n";
            else if (result == 0)
                cout << "No edge found!\n";
            else
                cout << "Edge with weight " << result << " exists between these vertices.\n";
        }
        else if (choice == 4)
        {
            GL.display();
        }
    }

    return 0;
}

graphList::graphList()
{
    for (int i = 0; i < SIZE; i++)
    {
        list[i] = NULL;
    }
}

// Function to insert an edge
int graphList::insertEdge(int inVer1, int inVer2, int inWeight)
{
    if (inVer1 >= SIZE || inVer2 >= SIZE || inVer1 < 0 || inVer2 < 0)
    {
        return -2;
    }

    if (searchEdge(inVer1, inVer2) != 0)
    {
        return -1;
    }

    vertex *newVertex = new vertex;
    newVertex->label = inVer2;
    newVertex->weight = inWeight;

    if (list[inVer1] == NULL)
    {
        newVertex->next = NULL;
        list[inVer1] = newVertex;

        return 0;
    }
    else
    {
        newVertex->next = list[inVer1];
        list[inVer1] = newVertex;

        return 0;
    }
}

// Function to delete an edge
int graphList::deleteEdge(int inVer1, int inVer2)
{
    if (inVer1 >= SIZE || inVer2 >= SIZE || inVer1 < 0 || inVer2 < 0)
    {
        return -2;
    }

    if (searchEdge(inVer1, inVer2) == 0)
    {
        return -1;
    }

    vertex *temp = list[inVer1];

    if (temp->label == inVer2)
    {
        int retWeight = temp->weight;
        list[inVer1] = temp->next; 

        delete temp;
        return retWeight;
    }

    while (temp->next != NULL)
    {
        if (temp->next->label == inVer2)
        {
            vertex *toDelete = temp->next;
            int retWeight = temp->next->weight;
            temp->next = temp->next->next;
    
            delete toDelete;
            return retWeight;
        }

        if (temp->next == NULL)
            break;
        
        temp = temp->next;
    }

    return -1;
}

// Function to check if an edge exists
int graphList::searchEdge(int inVer1, int inVer2)
{
    if (inVer1 >= SIZE || inVer2 >= SIZE || inVer1 < 0 || inVer2 < 0)
    {
        return -1;
    }

    vertex *temp = list[inVer1];

    while (temp != NULL)
    {
        if (temp->label == inVer2)
        {
            return temp->weight;                                                 
        }
        temp = temp->next;
    }

    return 0;
}

// Function to display the adjacency list
void graphList::display()
{
    for (int i = 0; i < SIZE; i++)
    {
        vertex *temp = list[i];

        std::cout << i;

        while (temp != NULL)
        {
            std::cout << " -> " << temp->label << "[" << temp->weight << "]";
            temp = temp->next;
        }
        // std::cout << "--" << temp->weight << "->" << temp->label;
        std::cout << "\n";
    }
}