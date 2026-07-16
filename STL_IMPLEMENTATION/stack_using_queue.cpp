#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q;

public:

    // Push element
    void push(int x)
    {
        int n = q.size();

        // Insert new element
        q.push(x);

        // Move all previous elements behind it
        for(int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Remove top element
    void pop()
    {
        if(q.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        q.pop();
    }

    // Return top element
    int top()
    {
        if(q.empty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }

        return q.front();
    }

    // Check empty
    bool empty()
    {
        return q.empty();
    }

    // Size
    int size()
    {
        return q.size();
    }

    // Display stack
    void display()
    {
        if(q.empty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        queue<int> temp = q;

        cout << "Stack: ";

        while(!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main()
{
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top = " << st.top() << endl;

    st.pop();

    st.display();
}