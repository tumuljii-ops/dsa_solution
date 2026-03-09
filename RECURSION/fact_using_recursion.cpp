#include <bits/stdc++.h>
using namespace std;

int fact(int n){

    if(n<=1) return 1;

    return n*fact(n-1);
}

int sum(int n){
    if(n<=1) return n;

    return n+sum(n-1);
}

int main(){
    int number;
    cin>>number;

    int a =fact(number);

    cout<<a<<'\n';

    // sum of numbers will be

    int b=sum(number);
    cout<<b<<'\n';
}