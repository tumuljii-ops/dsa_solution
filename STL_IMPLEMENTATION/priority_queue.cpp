#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:

    vector<int> heap;

    // Move newly inserted element upward
    void heapifyUp(int index)
    {
        while(index > 0)
        {
            int parent = (index - 1) / 2;

            // Parent is already larger
            if(heap[parent] >= heap[index])
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

            int largest = index;

            // Check left child
            if(left < size && heap[left] > heap[largest])
                largest = left;

            // Check right child
            if(right < size && heap[right] > heap[largest])
                largest = right;

            // Heap property satisfied
            if(largest == index)
                break;

            swap(heap[index], heap[largest]);

            index = largest;
        }
    }

public:

    // Insert element
    void push(int value)
    {
        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    // Remove maximum element
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

    // Return maximum element
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
    MaxHeap h;

    h.push(30);
    h.push(50);
    h.push(20);
    h.push(10);
    h.push(40);

    h.display();

    cout << "Max = " << h.top() << endl;

    h.pop();

    h.display();
}