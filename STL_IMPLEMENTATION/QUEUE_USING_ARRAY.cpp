#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:

    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];

        front = 0;
        rear = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    // Insert element
    void push(int value)
    {
        if(rear == capacity - 1)
        {
            cout << "Queue Overflow\n";
            return;
        }

        rear++;
        arr[rear] = value;
    }

    // Remove element
    void pop()
    {
        if(empty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        front++;
    }

    // Return front element
    int Front()
    {
        if(empty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[front];
    }

    bool empty()
    {
        return front > rear;
    }

    int size()
    {
        if(empty())
            return 0;

        return rear - front + 1;
    }

    void display()
    {
        if(empty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        for(int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    q.pop();

    q.display();

    cout << "Front = " << q.Front() << endl;
}