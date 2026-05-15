class Solution {
public:
    int maximumScore(int a, int b, int c) {

        vector<int> ans = {a, b, c};

        sort(ans.begin(), ans.end());

        int count = 0;
        
        if(ans[2] >= ans[0] + ans[1]) {

            count = ans[0] + ans[1];
        }

        else {

            count = (ans[0] + ans[1] + ans[2]) / 2;
        }

        return count;
    }
};