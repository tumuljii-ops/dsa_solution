#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    // Start from second element
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];

        int j = i - 1;

        // Shift all larger elements to the right
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at correct position
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> arr = {7, 2, 9, 1, 5, 4};

    insertionSort(arr);

    for(int x : arr)
        cout << x << " ";
}