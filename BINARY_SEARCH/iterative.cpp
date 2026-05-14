#include <bits/stdc++.h>
using namespace std;

bool binary_search(int arr[], int target) {

    int low = 0;
    int high = 4;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return false;
}

int main() {

    int target = 5;

    int arr[5] = {1, 2, 3, 4, 5};

    bool ans;

    ans = binary_search(arr, target);

    cout << ans << endl;
}