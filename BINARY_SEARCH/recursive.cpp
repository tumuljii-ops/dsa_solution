#include <bits/stdc++.h>
using namespace std;

bool binary_search(int arr[], int low, int high, int target) {

    if (low > high) {
        return false;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return true;
    }
    else if (arr[mid] > target) {
        return binary_search(arr, low, mid - 1, target);
    }
    else {
        return binary_search(arr, mid + 1, high, target);
    }
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    int target = 4;

    bool ans = binary_search(arr, 0, 4, target);

    cout << ans << endl;
}