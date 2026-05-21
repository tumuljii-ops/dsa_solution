class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        int count = 0;
        int l = 0, r = 0;
        int n = nums.size();
        map<int, int> mpp;

        while (r < n) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
};
