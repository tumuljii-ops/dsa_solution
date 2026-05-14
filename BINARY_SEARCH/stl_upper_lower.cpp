#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = {1,2,4,4,4,6,8};

    int target = 4;

    int lb = lower_bound(v.begin(), v.end(), target) - v.begin();

    int ub = upper_bound(v.begin(), v.end(), target) - v.begin();

    cout << "Lower Bound = " << lb << endl;

    cout << "Upper Bound = " << ub << endl;
}