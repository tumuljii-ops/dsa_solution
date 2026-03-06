#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {

    if(left > right){
        return -1;
    }

    int mid = left + (right - left) / 2;

    if(arr[mid] == target){
        return mid;
    }

    else if(arr[mid] > target){
        return binarySearch(arr, left, mid - 1, target);
    }

    else{
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main(){

    int arr[] = {2,4,6,8,10,12,14};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 10;

    int result = binarySearch(arr, 0, n-1, target);

    if(result != -1){
        cout << "Element found at index: " << result;
    }
    else{
        cout << "Element not found";
    }

    return 0;
}