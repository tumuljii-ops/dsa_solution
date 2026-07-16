#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];      // Choose last element as pivot
    int i = low - 1;            // Index of smaller element

    for(int j = low; j < high; j++)
    {
        // Place smaller elements before pivot
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in its correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high)
{
    if(low >= high)
        return;

    int pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);

    quickSort(arr, pivotIndex + 1, high);
}

int main()
{
    vector<int> arr = {7, 2, 9, 1, 5, 4};

    quickSort(arr, 0, arr.size() - 1);

    for(int x : arr)
        cout << x << " ";
}