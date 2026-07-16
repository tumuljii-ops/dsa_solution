#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:

    stack<int> input;
    stack<int> output;

public:

    // Insert into queue
    void push(int x)
    {
        // Always push into input stack
        input.push(x);
    }

    // Remove front element
    void pop()
    {
        if(empty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        // If output stack is empty,
        // transfer all elements
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        output.pop();
    }

    // Return front element
    int Front()
    {
        if(empty())
        {
            cout << "Queue Empty\n";
            return -1;
        }

        // Transfer only when needed
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }

    int size()
    {
        return input.size() + output.size();
    }

    void display()
    {
        cout << "Display is not implemented because elements are split across two stacks.\n";
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.Front() << endl;

    q.pop();

    cout << q.Front() << endl;

    q.push(40);

    cout << q.Front() << endl;
}