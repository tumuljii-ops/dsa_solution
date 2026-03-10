#include <bits/stdc++.h>
using namespace std;

void printSubset(string ans, int ind, string str) {
    if(ind == str.size()) {
        cout << ans << '\n';
        return;
    }

    printSubset(ans + str[ind], ind + 1, str);
    printSubset(ans, ind + 1, str);
}

vector<string> getSubset(string ans, int ind, string str) {
    vector<string> anss;

    if(ind == str.size()) {
        anss.push_back(ans);
        return anss;
    }

    vector<string> left = getSubset(ans + str[ind], ind + 1, str);
    vector<string> right = getSubset(ans, ind + 1, str);

    for(int i = 0; i < left.size(); i++) {
        anss.push_back(left[i]);
    }

    for(int i = 0; i < right.size(); i++) {
        anss.push_back(right[i]);
    }

    return anss;
}

int main() {
    string ans = "";
    string str = "abc";

    printSubset(ans, 0, str);

    vector<string> result = getSubset(ans, 0, str);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}