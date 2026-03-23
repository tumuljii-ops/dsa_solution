#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter a number n";
    cin>>n;
    int count=0;

     while(n){

         if(n&1){
           count=count+1;
         }
         n=n>>1;
     }

     cout<<count;
}