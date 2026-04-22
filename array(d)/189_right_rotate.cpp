class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n=nums.size();
         
         vector<int>ans;
         ans=nums;

         for(int i=0;i<n;i++){
            nums[(i+k)%n]=ans[i];
         }

         //return ans;
    }
};