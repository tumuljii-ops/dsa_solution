#include <bits/stdc++.h>
using namespace std;

template<typename T>

T maximum(T a,T b){
     
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
     
    cout<<maximum(5,7)<<endl;

    cout<<maximum(6.5,7.5)<<endl;

    return 0;
}


