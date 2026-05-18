class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
           
           sort(nums.begin(),nums.end());

           for(int i=0;i<nums.size();i++){
                  
                   if(nums[i]<0 && k>0){
                        k--;
                        nums[i]=-nums[i];
                   }
           }

           sort(nums.begin(),nums.end());

           while(k>0){
               nums[0]=-nums[0];
               k--;
           }

           int sum=0;

           for(int i=0;i<nums.size();i++){
               sum+=nums[i];
           }

           return sum;
    }
};