#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n, int rev){

    if(n == 0){
        return rev;
    }

    int digit = n % 10;

    rev = rev * 10 + digit;

    return reverseNumber(n / 10, rev);
}

int main(){

    int n;
    cin >> n;

    int ans = reverseNumber(n, 0);

    cout << ans;

    return 0;
}