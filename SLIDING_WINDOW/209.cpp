class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {

        int l = 0;
        int r = 0;
        int n = nums.size();

        int sum = 0;

        int len = INT_MAX;

        while(r < n) {

            sum += nums[r];

            while(sum >= target) {

                len = min(len, r - l + 1);

                sum -= nums[l];
                l++;
            }

            r++;
        }

        if(len != INT_MAX) {
            return len;
        }

        return 0;
    }
};