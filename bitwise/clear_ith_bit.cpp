#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter a number n:";
    cin>>n;

    //clear bit formula will be 
    int pos;
    cout<<"enter position";
    cin>>pos;

    int num=(n&~(1<<pos));
    cout<<num;

    return 0;
}