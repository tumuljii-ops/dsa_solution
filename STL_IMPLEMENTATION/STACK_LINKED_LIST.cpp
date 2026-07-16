#include <iostream>
using namespace std;

// Node of linked list
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

// Stack class
class Stack
{
private:

    Node* topNode;
    int currentSize;

public:

    Stack()
    {
        topNode = NULL;
        currentSize = 0;
    }

    // Push element
    void push(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = topNode;

        topNode = newNode;

        currentSize++;
    }

    // Pop element
    void pop()
    {
        if(topNode == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = topNode;

        topNode = topNode->next;

        delete temp;

        currentSize--;
    }

    // Return top element
    int top()
    {
        if(topNode == NULL)
        {
            cout << "Stack is Empty\n";
            return -1;
        }

        return topNode->data;
    }

    // Check empty
    bool empty()
    {
        return topNode == NULL;
    }

    // Size
    int size()
    {
        return currentSize;
    }

    // Display stack
    void display()
    {
        if(empty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        Node* curr = topNode;

        cout << "Stack: ";

        while(curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    // Destructor
    ~Stack()
    {
        while(topNode != NULL)
        {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top = " << st.top() << endl;

    st.pop();

    st.display();

    cout << "Size = " << st.size() << endl;

    return 0;
}