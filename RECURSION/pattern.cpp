#include <bits/stdc++.h>
using namespace std;

void pattern(int row,int col){
      if(row==0) return;

      if(col<row){
        cout<<'*';
        pattern(row,col+1);
      }
      else{
        cout<<'\n';
        pattern(row-1,0);
      }

}

int main(){

    pattern(4,0);
}