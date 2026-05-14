#include <bits/stdc++.h>
using namespace std;

int lower_bound_custom(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;

    // if no answer exists,
    // return n (insertion at end)
    int ans = n;

    while (low <= high) {

        int mid = (low + high) / 2;

        // possible answer found
        if (arr[mid] >= target) {

            ans = mid;

            // search on LEFT side
            // to find smaller valid index
            high = mid - 1;
        }
        else {

            // answer must be on RIGHT
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int arr[] = {1,2,4,4,4,6,8};

    int n = 7;

    int target = 4;

    cout << lower_bound_custom(arr, n, target);
}