#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:

    vector<int> heap;

    // Move newly inserted element upward
    void heapifyUp(int index)
    {
        while(index > 0)
        {
            int parent = (index - 1) / 2;

            // Parent is already smaller
            if(heap[parent] <= heap[index])
                break;

            swap(heap[parent], heap[index]);

            index = parent;
        }
    }

    // Restore heap after deleting root
    void heapifyDown(int index)
    {
        int size = heap.size();

        while(true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int smallest = index;

            // Check left child
            if(left < size && heap[left] < heap[smallest])
                smallest = left;

            // Check right child
            if(right < size && heap[right] < heap[smallest])
                smallest = right;

            // Heap property satisfied
            if(smallest == index)
                break;

            swap(heap[index], heap[smallest]);

            index = smallest;
        }
    }

public:

    // Insert element
    void push(int value)
    {
        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    // Remove minimum element
    void pop()
    {
        if(heap.empty())
        {
            cout << "Heap Empty\n";
            return;
        }

        heap[0] = heap.back();

        heap.pop_back();

        if(!heap.empty())
            heapifyDown(0);
    }

    // Return minimum element
    int top()
    {
        if(heap.empty())
        {
            cout << "Heap Empty\n";
            return -1;
        }

        return heap[0];
    }

    bool empty()
    {
        return heap.empty();
    }

    int size()
    {
        return heap.size();
    }

    void display()
    {
        for(int x : heap)
            cout << x << " ";

        cout << endl;
    }
};

int main()
{
    MinHeap h;

    h.push(30);
    h.push(50);
    h.push(20);
    h.push(10);
    h.push(40);

    h.display();

    cout << "Min = " << h.top() << endl;

    h.pop();

    h.display();
}