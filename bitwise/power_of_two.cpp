#include <bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cout<<"enter a number n:";
     cin>>n;

     if((n&(n-1))==0){
        cout<<"number is power of two:";
     }
     else {
        cout<<"number is not a power of two";
     }

     return 0;

}