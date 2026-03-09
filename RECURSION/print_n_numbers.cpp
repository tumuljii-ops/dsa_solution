#include <bits/stdc++.h>
using namespace std;

void f(int n){
     
    if(n==1){
        cout<<n<<'\n';
        return ;

    }
    cout<<n<<'\n';
    f(n-1);



}

void print_1_to_5(int n){
    if(n==0){
        return ;
    }

    print_1_to_5(n-1);
    cout<<n<<'\n';
}
void fun_both(int number){
      if(number==0){
        return ;
      }

      cout<<number<<'\n';
      fun_both(number-1);
      cout<<number<<'\n';
}

int main(){
     int n;
     cin>>n;

     // f(n);

    // print_1_to_5(n);
    fun_both(n);

     return 0;
}

