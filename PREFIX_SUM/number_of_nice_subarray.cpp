class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> ans(nums.size());

        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] % 2 == 0) ans[i] = 0;
            else ans[i] = 1;  
        }

        int prefixsum = 0;
        mpp[0] = 1;
        int count = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            prefixsum += ans[i];  

            if (mpp.find(prefixsum - k) != mpp.end()) {
                count += mpp[prefixsum - k]; 
            }

            mpp[prefixsum]++;
        }

        return count;
    }
};