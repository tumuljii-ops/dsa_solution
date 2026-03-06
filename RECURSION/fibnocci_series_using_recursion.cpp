#include <bits/stdc++.h>
using namespace std;

int fib(int number){
     if(number==0||number==1){
        return number;
     }

     int a=fib(number-1);
     int b=fib(number-2);

     return a+b;

}

int main(){
     int n;
     cout<<"enter number"<<'\n';

     cin>>n;

    int fib_number= fib(n);

    cout<<"nth fibnocii number is:"<<fib_number;

}