#include <bits/stdc++.h>
using namespace std;

int hcf(int a,int b){
    
    while(a!=0){
        int temp=b%a;
        b=a;
        a=temp;
    }
    return b;r
}

int main(){
    int a=9;
    int b=12;

    cout<<hcf(a,b);
}