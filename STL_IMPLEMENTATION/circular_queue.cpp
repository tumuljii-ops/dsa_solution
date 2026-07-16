#include <iostream>
using namespace std;

class CircularQueue
{
private:

    int *arr;
    int front;
    int rear;
    int capacity;
    int currentSize;

public:

    CircularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];

        front = 0;
        rear = 0;
        currentSize = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    // Insert
    void push(int value)
    {
        if(currentSize == capacity)
        {
            cout << "Queue Overflow\n";
            return;
        }

        arr[rear] = value;

        rear = (rear + 1) % capacity;

        currentSize++;
    }

    // Remove
    void pop()
    {
        if(currentSize == 0)
        {
            cout << "Queue Underflow\n";
            return;
        }

        front = (front + 1) % capacity;

        currentSize--;
    }

    // Front element
    int Front()
    {
        if(currentSize == 0)
        {
            cout << "Queue Empty\n";
            return -1;
        }

        return arr[front];
    }

    bool empty()
    {
        return currentSize == 0;
    }

    int size()
    {
        return currentSize;
    }

    void display()
    {
        if(empty())
        {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Queue: ";

        int index = front;

        for(int i = 0; i < currentSize; i++)
        {
            cout << arr[index] << " ";

            index = (index + 1) % capacity;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();

    q.pop();
    q.pop();

    q.display();

    q.push(50);
    q.push(60);

    q.display();

    return 0;
}