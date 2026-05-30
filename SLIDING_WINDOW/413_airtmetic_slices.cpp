class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();

        if(n < 3) return 0;

        int left = 0;
        int right = 1;

        int diff = nums[1] - nums[0];

        int count = 0;

        while(right < n) {

            if(nums[right] - nums[right - 1] == diff) {

                if(right - left + 1 >= 3) {
                    count += (right - left - 1);
                }

                right++;
            }
            else {

                left = right - 1;

                if(right < n)
                    diff = nums[right] - nums[left];

                right++;
            }
        }

        return count;
    }
};