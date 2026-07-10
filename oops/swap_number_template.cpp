#include <bits/stdc++.h>
using namespace std;

template <typename T>

void swap(T &a, T &b){
     
     T temp=a;
     a=b;
     b=temp;
}

int main(){
     
     int x=10;
     int y=20;
     
     swap(x,y);

     cout<<x<<endl;
     cout<<y<<endl;

     return 0;

}