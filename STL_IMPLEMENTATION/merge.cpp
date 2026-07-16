#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves
void merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Compare elements from both halves
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    // Remaining left half
    while(left <= mid)
        temp.push_back(arr[left++]);

    // Remaining right half
    while(right <= high)
        temp.push_back(arr[right++]);

    // Copy back to original array
    for(int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

// Merge Sort
void mergeSort(vector<int>& arr, int low, int high)
{
    if(low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);

    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {7, 2, 9, 1, 5, 4};

    mergeSort(arr, 0, arr.size() - 1);

    for(int x : arr)
        cout << x << " ";
}