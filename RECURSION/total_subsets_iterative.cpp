#include <bits/stdc++.h>
using namespace std;

vector<string> subset(string str){

    vector<string> ans;
    ans.push_back("");   // empty subset

    for(int i = 0; i < str.size(); i++){

        int n = ans.size();

        for(int j = 0; j < n; j++){
            ans.push_back(ans[j] + str[i]);
        }
    }

    return ans;
}

int main(){

    string str = "abc";

    vector<string> result = subset(str);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }

}