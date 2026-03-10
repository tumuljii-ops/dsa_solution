#include <bits/stdc++.h>
using namespace std;

string removeABC(string s) {

    if(s.size() == 0){
        return "";
    }

    if(s.substr(0,3) == "abc"){
        return removeABC(s.substr(3));
    }
    else{
        char ch = s[0];
        string smallAns = removeABC(s.substr(1));
        return ch + smallAns;
    }
}

int main(){

    string s = "abcdefgh";

    cout << removeABC(s);

}