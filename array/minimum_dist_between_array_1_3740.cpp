class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();
        int m = 3;

        vector<int> ans = nums;
        sort(ans.begin(), ans.end());

        int maxi = ans[n - 1];

        vector<vector<int>> anss(maxi + 1);
        vector<int> hash(maxi + 1, false);

        for (int i = 2; i < ans.size(); i++) {
            if (ans[i] == ans[i - 2]) {
                hash[ans[i]] = true;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]] == true) {
                anss[nums[i]].push_back(i);
            }
        }

        int mini = INT_MAX;

        for (int i = 0; i <= maxi; i++) {

            if (anss[i].size() >= 3) {

                for (int j = 0; j + 2 < anss[i].size(); j++) {

                    int a = anss[i][j];
                    int b = anss[i][j + 1];
                    int c = anss[i][j + 2];

                    int sum = abs(a - b) + abs(b - c) + abs(c - a);

                    mini = min(mini, sum);
                }
            }
        }

        if(mini==INT_MAX) return -1;
        else return mini;
    }
};