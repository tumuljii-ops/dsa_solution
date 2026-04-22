class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 0);

        long long prod = 1;
        int zeroCount = 0;

        // Calculate product of non-zero elements
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zeroCount++;
            } else {
                prod *= nums[i];
            }
        }

        // Case handling
        if(zeroCount > 1){
            return ans;   // all zeros
        }

        for(int i = 0; i < n; i++){
            if(zeroCount == 0){
                ans[i] = prod / nums[i];
            }
            else { 
                if(nums[i] == 0)
                    ans[i] = prod;
                else
                    ans[i] = 0;
            }
        }

        return ans;
    }
};
