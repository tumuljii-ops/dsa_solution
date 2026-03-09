#include <bits/stdc++.h>
using namespace std;

bool issorted(int arr[], int ind){

    if(ind == 4){
        return true;
    }

    if(arr[ind] < arr[ind+1]){
        return issorted(arr, ind+1);
    }
    else{
        return false;
    }
}

int main(){

    int arr[5] = {1,2,3,4,5};

    bool ans = issorted(arr,0);

    cout << ans;

}