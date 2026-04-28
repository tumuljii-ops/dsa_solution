class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int x : nums) sum += x;

        int need = (int)(sum % p);
        if (need == 0) return 0;

        unordered_map<int,int> mpp;   
        mpp[0] = -1;

        long long prefixsum = 0;
        int ans = nums.size();

        for (int i = 0; i < (int)nums.size(); i++) {
            prefixsum += nums[i];
            int cur = (int)(prefixsum % p);

            int target = (cur - need) % p;
            if (target < 0) target += p;

            if (mpp.find(target) != mpp.end()) {
                ans = min(ans, i - mpp[target]);
            }

            mpp[cur] = i;
        }

        return (ans == (int)nums.size()) ? -1 : ans;
    }
};