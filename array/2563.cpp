class Solution {
public:
    
    long long countLessEqual(vector<int>& nums, int target) {
        
        int i = 0, j = nums.size() - 1;
        long long count = 0;
        
        while(i < j) {
            
            if(nums[i] + nums[j] <= target) {
                count += (j - i);
                i++;
            }
            else {
                j--;
            }
        }
        
        return count;
    }
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(), nums.end());
        
        return countLessEqual(nums, upper) - countLessEqual(nums, lower - 1);
    }
};
