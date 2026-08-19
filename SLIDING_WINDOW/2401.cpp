class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
          
           int max_len=0;
           int n=nums.size();

           for(int i=0;i<n;i++){
               
                int current_xor=0;

                for(int j=i;j<n;j++){
                     
                      if((current_xor & nums[j]) !=0){
                           break;
                      }

                      current_xor|=nums[j];

                      max_len=max(max_len,j-i+1);
                }
           }

           return max_len;
    }
};