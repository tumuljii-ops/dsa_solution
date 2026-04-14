// User function template for C++
class Solution {
  public:
    
    int memo(int ind,vector<int>&dp,vector<int>&arr){
         int n=arr.size();
         
         if(ind>=n) return 0;
         
         //if(ind==n-1) return arr[ind];
         
         if(dp[ind]!=-1) return dp[ind];
         
         int not_take=memo(ind+1,dp,arr);
         
         int take=0;
         
        
         take=arr[ind]+memo(ind+2,dp,arr);
         
         return dp[ind]=max(take,not_take);
    }
    
    int findMaxSum(vector<int>& arr) {
         int n=arr.size();
         
         vector<int>dp(n+1,-1);
         
         return memo(0,dp,arr);
         
    }
};