class Solution {
public:

    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int l = 0;
        int r = 0;
        int n = nums.size();

        long long sum = 0;

        long long maxi = 0;

        while(r < n) {

            sum += nums[r];

            mp[nums[r]]++;

            if((r - l + 1) > k) {

                mp[nums[l]]--;

                if(mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }

                sum -= nums[l];

                l++;
            }

            if((r - l + 1) == k && mp.size() == k) {

                maxi = max(maxi, sum);
            }

            r++;
        }

        return maxi;
    }
};