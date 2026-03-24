#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter a number n";
    cin>>n;

    int pos;
    cin>>pos;

    int num=(n|(1<<pos));

    cout<<num;
}