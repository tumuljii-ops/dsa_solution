class Solution {
public:
    
    int maxi = 0;
    int count = 0;
    
    void solve(int idx, vector<int>& nums, int currOR) {
        
        if(idx == nums.size()) {
            
            if(currOR > maxi) {
                maxi = currOR;
                count = 1;
            }
            else if(currOR == maxi) {
                count++;
            }
            
            return;
        }
        
        // take
        solve(idx + 1, nums, currOR | nums[idx]);
        
        // not take
        solve(idx + 1, nums, currOR);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        solve(0, nums, 0);
        
        return count;
    }
};