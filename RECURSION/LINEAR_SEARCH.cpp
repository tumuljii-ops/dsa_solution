#include <bits/stdc++.h>
using namespace std;

bool search(int *arr, int target, int ind, int n){

    if(ind == n){
        return false;
    }

    if(arr[ind] == target){
        return true;
    }

    return search(arr, target, ind + 1, n);
}

int main(){

    int arr[5] = {1,2,3,4,5};
    int target = 3;

    bool ans = search(arr, target, 0, 5);

    cout << ans << '\n';
}