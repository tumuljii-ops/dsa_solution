#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int n){
    if(n<=9){
        return n;
    }

    return (n%10)+sum_of_digits(n/10);
}

int main(){
     
    int number=1234;

    int res=sum_of_digits(number);

    cout<<res<<'\n';
}