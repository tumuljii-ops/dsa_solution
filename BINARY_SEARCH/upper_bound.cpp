#include <bits/stdc++.h>
using namespace std;

int upper_bound_custom(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;

    // default answer if no greater element exists
    int ans = n;

    while (low <= high) {

        int mid = (low + high) / 2;

        // possible answer found
        if (arr[mid] > target) {

            ans = mid;

            // try finding smaller valid index
            high = mid - 1;
        }
        else {

            // move RIGHT
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int arr[] = {1,2,4,4,4,6,8};

    int n = 7;

    int target = 4;

    cout << upper_bound_custom(arr, n, target);
}

//------------------VVVVIMPORTANT----------------------

// TO CALCULATE THE FREQUENCY OF ANY ELEMENT WE CAN FIND LIKE  {frequency = upper_bound - lower_bounD}