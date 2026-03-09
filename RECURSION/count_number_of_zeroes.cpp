#include <bits/stdc++.h>
using namespace std;

int number_of_zeroes(int number,int count){

    if(number == 0){
        return count;
    }

    int num = number % 10;

    if(num == 0){
        return number_of_zeroes(number/10, count + 1);
    }
    else{
        return number_of_zeroes(number/10, count);
    }
}

int main(){

    int n = 10000;

    int a = number_of_zeroes(n,0);

    cout << a << '\n';

    return 0;
}