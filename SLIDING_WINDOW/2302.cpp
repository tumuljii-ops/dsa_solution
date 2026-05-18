class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long l = 0;
        long long r = 0;

        long long sum = 0;
        long long count = 0;

        while(r < nums.size()) {

            // expand window
            sum += nums[r];

            // shrink window until valid
            while(sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }

            // all subarrays ending at r are valid
            count += (r - l + 1);

            r++;
        }

        return count;
    }
};