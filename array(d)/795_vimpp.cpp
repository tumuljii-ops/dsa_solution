class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
             
               int last_valid=-1;
               int last_invalid=-1;

               int n=nums.size();
               int ans=0;

               for(int i=0;i<n;i++){
                  
                     if(nums[i]>right){
                        last_invalid=i;
                     }

                     if(nums[i]>=left && nums[i]<=right){
                          last_valid=i;
                     }

                     ans+=max(0,last_valid-last_invalid);


               }

               return ans;
    }
};