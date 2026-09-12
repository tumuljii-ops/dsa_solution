class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
           
             int n=nums.size();

             if(n<=1) return 0;

             int i=0;

             int max_len=0;

             sort(nums.begin(),nums.end());

             for(int j=0;j<n;j++){
                 
                  while(i<=j && (long long)nums[j] > (long long)k*nums[i]){
                        
                             i++;
                  }

                  max_len=max(max_len,j-i+1);
             }

             return n-max_len;
    }
};