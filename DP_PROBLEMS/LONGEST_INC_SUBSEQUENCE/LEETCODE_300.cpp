class Solution {
public:
    int memo(int prev,vector<vector<int>>&dp,vector<int>&nums,int ind){

         if(ind>=nums.size()) return 0;
         
          if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

          int skip=memo(prev,dp,nums,ind+1);

          int total=0;

          if(prev==-1 || nums[prev]<nums[ind]){
              total=1+memo(ind,dp,nums,ind+1);
          }

          return dp[ind][prev+1]=max(skip,total);
    }
    int lengthOfLIS(vector<int>& nums) {

          int n=nums.size();
          int prev=-1;
          
          vector<int>dp(n,1);

          int ans=1;

          for(int i=0;i<n;i++){
              for(int j=0;j<i;j++){
                 
                  if(nums[j]<nums[i]){
                     dp[i]=max(dp[i],dp[j]+1);
                  }
              }

              ans=max(ans,dp[i]);
          }

          return ans;

    }
};