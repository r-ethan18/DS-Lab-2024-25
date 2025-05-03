// Program to implement Queue using an array of size 5

#include <iostream>

class queue
{
private:
    int data[5];
    int back;

public:
    queue();
    int enqueue(int);
    int dequeue();
    int peek();
    void display();
};

int main()
{
    queue myQueue;
    int choice = 0;

    while (choice != 4)
    {
        std::cout << "\nMENU:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Exit\n";

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int usrData;
            std::cout << "Enter the Number to be enqueued: ";
            std::cin >> usrData;

            int status = myQueue.enqueue(usrData);

            if (status == 1)
            {
                std::cout << "Queue Full!\n";
            }
            else
            {
                std::cout << usrData << " enqueued successfully!\n";
                myQueue.display();
            }
        }
        else if (choice == 2)
        {
            int dequeued = myQueue.dequeue();

            if (dequeued == -1)
            {
                std::cout << "Queue Empty!\n";
            }
            else
            {
                std::cout << "Dequeued " << dequeued << "\n";
                myQueue.display();
            }
        }
        else if (choice == 3)
        {
            int peeked = myQueue.peek();

            if (peeked == -1)
            {
                std::cout << "Queue Empty!\n";
            }
            else
            {
                std::cout << peeked << " is at position 0\n";
            }
        }
    }
}

queue::queue()
{
    back = -1;
}

// Function to enqueue a value to the end of the queue
int queue::enqueue(int inData)
{
    if (back == 4)
    {
        return 1;
    }
    else
    {
        data[back + 1] = inData;
        back++;
        return 0;
    }
}

// Function to dequeue the element from the 0th index of the queue
int queue::dequeue()
{
    if (back == -1)
    {
        return -1;
    }
    else
    {
        int returnElem = data[0];

        // Shifting to the left
        for (int i = 0; i < back; i++)
        {
            data[i] = data[i + 1];
        }

        back--;

        return returnElem;
    }
}

// Function to return the elemnent at the 0th position without dequeing it
int queue::peek()
{
    if (back == -1)
    {
        return -1;
    }
    else
    {
        return (data[0]);
    }
}

// Function to display the elements in the queue
void queue::display()
{
    if (back == -1)
    {
        std::cout << "Queue Empty!\n";
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            std::cout << data[i] << ", ";
        }
        std::cout << data[back] << "\n";
    }
}