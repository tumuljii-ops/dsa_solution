class Solution {
public:

    int solve(vector<vector<int>>&dp,vector<int>&nums,int target,int ind,int xorr){
         
          if(ind==nums.size()){
             
               if(xorr==target){
                   return 0;
               }

               return mini;
          }

          if(dp[ind][xorr]!=-1) return dp[ind][xorr];

          int skip=solve(dp,nums,target,ind+1,xorr);

          int take=1+solve(dp,nums,target,ind+1,xorr^nums[ind]);

          return dp[ind][xorr]=max(take,skip);
    }
    int minRemovals(vector<int>& nums, int target) {
        
          int n=nums.size();

          vector<vector<int>>dp(n+1,vector<int>(16384,-1));

          int keep=solve(dp,nums,target,0,0);

          if(keep<0){
            return -1;
          }

          return n-keep;
    }
};