class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int count = 0;
        int total = 0;

        for (r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 == 1) {
                count++;
            }

            while (count > k) {
                if (nums[l] % 2 == 1) {
                    count--;
                }
                l++;
            }

            total += (r - l + 1);
        }

        return total;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};