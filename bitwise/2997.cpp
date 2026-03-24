class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         int x=0;

         for(int i=0;i<nums.size();i++){
            x=x^nums[i];
         }

         int ans=x^k;

         int count=0;

         while(ans){
             if(ans&1){
                count++;
             }
             ans=ans>>1;
         }

         return count;
    }
};