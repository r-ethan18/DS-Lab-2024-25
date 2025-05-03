// Program to implement a Queue using a circular array

#include <iostream>

class queue
{
private:
    int data[5];
    int back;
    int front;

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
    front = -1;
}

// Function to enqueue a value to the end of the queue
int queue::enqueue(int inData)
{
    if (front == -1 && back == -1)
    {
        front = 0;
        back = 0;

        data[back] = inData;

        return 0;
    }
    else if (back == front - 1 || (back == 4 && front == 0))
    {
        return 1;
    }
    else
    {
        back = (back + 1) % 5;
        data[back] = inData;

        return 0;
    }
}

// Function to dequeue the element from the 0th index of the queue
int queue::dequeue()
{
    if (front == back && (front != -1 && back != -1))
    {
        int returnElem = data[front];
        front = -1;
        back = -1;

        return returnElem;
    }
    else if (front == -1 && back == -1)
    {
        return -1;
    }
    else
    {
        int returnElem = data[front];

        front = (front + 1) % 5;

        return returnElem;
    }
}

// Function to return the elemnent at the 0th position without dequeing it
int queue::peek()
{
    if (front == -1 && back == -1)
    {
        return -1;
    }
    else
    {
        return data[front];
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
        int pos = front;

        while (pos % 5 != back)
        {
            std::cout << data[pos % 5] << " ";
            pos++;
        }
        std::cout << data[pos % 5] << "\n";
    }
}