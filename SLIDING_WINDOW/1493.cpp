class Solution {
public:
    int longestSubarray(vector<int>& nums) {
           
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        int count = 0;

        while(r < n){

            if(nums[r] == 0){
                count++;
            }

            while(count > 1){

                if(nums[l] == 0){
                    count--;
                }

                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans - 1;
    }
};