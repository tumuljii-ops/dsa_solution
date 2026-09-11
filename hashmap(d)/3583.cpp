class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        long long count = 0;
        int MOD = 1000000007;

        for (int i = 1; i < nums.size() - 1; i++) {
            
            long long target = (long long)nums[i] * 2;

            if (mpp.find(target) != mpp.end()) {
                 vector<int>& ans = mpp[target];

                long long left_count = lower_bound(ans.begin(), ans.end(), i) - ans.begin(); 

                auto it_right = upper_bound(ans.begin(), ans.end(), i);
                long long right_count = ans.end() - it_right;

                long long total_triplets = (left_count * right_count) % MOD;

                count = (count + total_triplets) % MOD;
            }
        }

        return count;
    }
};