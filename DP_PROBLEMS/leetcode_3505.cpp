class Solution {
private:

    long long helper(int idx, int rem, int x, int n, const vector<long long>& minOps, vector<vector<long long>>& memo) {
        if (rem == 0) return 0;
        if (idx >= n) return 1e18; 
        if (memo[idx][rem] != -1) return memo[idx][rem];

        long long skip = helper(idx + 1, rem, x, n, minOps, memo);

        long long pick = 1e18;
        if (idx + x <= n && minOps[idx] != -1) {
            pick = minOps[idx] + helper(idx + x, rem - 1, x, n, minOps, memo);
        }

        return memo[idx][rem] = min(skip, pick);
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
    
        vector<long long> minOps(n, -1);
        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;

        for (int i = 0; i < n; ++i) {
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }

            if (i >= x) {
                int outNum = nums[i - x];
                auto it = lower.find(outNum);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= outNum;
                } else {
                    upper.erase(upper.find(outNum));
                    upperSum -= outNum;
                }
            }

            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            } else if (lower.size() - upper.size() > 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }

            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
                minOps[i - x + 1] = ops;
            }
        }

        vector<vector<long long>> memo(n + 1, vector<long long>(k + 1, -1));
        
        return helper(0, k, x, n, minOps, memo);
    }
};