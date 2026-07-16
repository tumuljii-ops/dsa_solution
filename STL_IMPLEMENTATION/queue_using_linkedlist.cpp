#include <iostream>
using namespace std;

// Node of Linked List
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
private:

    Node* front;
    Node* rear;
    int currentSize;

public:

    Queue()
    {
        front = NULL;
        rear = NULL;
        currentSize = 0;
    }

    // Insert element at rear
    void push(int value)
    {
        Node* newNode = new Node(value);

        // Queue is empty
        if(front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            // Connect new node after rear
            rear->next = newNode;

            // Move rear pointer
            rear = newNode;
        }

        currentSize++;
    }

    // Remove element from front
    void pop()
    {
        if(front == NULL)
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;

        // Move front to next node
        front = front->next;

        // If queue becomes empty
        if(front == NULL)
            rear = NULL;

        delete temp;

        currentSize--;
    }

    // Return front element
    int Front()
    {
        if(front == NULL)
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        return front == NULL;
    }

    int size()
    {
        return currentSize;
    }

    void display()
    {
        if(empty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        Node* curr = front;

        cout << "Queue : ";

        while(curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    // Destructor
    ~Queue()
    {
        while(front != NULL)
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    q.pop();

    q.display();

    cout << "Front = " << q.Front() << endl;

    cout << "Size = " << q.size() << endl;
}