#include <bits/stdc++.h>
using namespace std;

void pattern(int row,int col){

    if(row == 0){
        return;
    }

    if(col < row){
        pattern(row, col + 1);
        cout << "*";
    }
    else{
        pattern(row - 1, 0);
        cout << '\n';
    }
}

int main(){
    pattern(4,0);
}