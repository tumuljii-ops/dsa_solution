// This problem is of Binary Search and Dp 

class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {

        // if widths same
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> temp;

        for (int i = 0; i < envelopes.size(); i++) {

            int h = envelopes[i][1];

            auto it = lower_bound(temp.begin(), temp.end(), h);

            if (it == temp.end()) {
                temp.push_back(h);
            }
            else {
                *it = h;
            }
        }

        return temp.size();
    }
};