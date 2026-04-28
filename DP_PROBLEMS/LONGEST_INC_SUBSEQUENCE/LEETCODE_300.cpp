class Solution {
public:
    int memo(int ind,int prev,vector<vector<int>>&dp,vector<int>&nums){
         
          if(ind==nums.size()) return 0;

          if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

          int skip=memo(ind+1,prev,dp,nums);
          int take=0;

          if(prev==-1||nums[prev]<nums[ind]){
            take=1+memo(ind+1,ind,dp,nums);
          }

          return dp[ind][prev+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
          
          int n=nums.size();

          vector<vector<int>>dp(n+1,vector<int>(n+1,0));

          for(int ind=n-1;ind>=0;ind--){

              for(int prevind=ind-1;prevind>=-1;prevind--){

                  int skip=dp[ind+1][prevind+1];

                  int take=0;

                  if(prevind==-1||nums[prevind]<nums[ind]){
                    take=1+dp[ind+1][ind+1];
                  }
              }
          }

           


    }
};