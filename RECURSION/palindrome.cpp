#include <bits/stdc++.h>
using namespace std;

int palindrome(int n,int sum){
        if(n==0){
            return sum;
        }

        int rem=n%10;

        sum=sum*10+rem;

    return palindrome(n/10,sum);
       
}

int main(){
      int number;
      cin>>number;

      int a=palindrome(number,0);

      if(a==number){
        cout<<"yes its a palindrome number";
      }
      else{
        cout<<"no its not a palindrome number";
      }

      return 0;
}