class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,dp,prices);
    }
    int f(int i,int buy,int k,vector<vector<vector<int>>>&dp,vector<int>&prices){
        if(i==prices.size()||k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(buy){
            return dp[i][buy][k]=max(-prices[i]+f(i+1,0,k,dp,prices),f(i+1,1,k,dp,prices));
        }
        else{
            return dp[i][buy][k]=max(prices[i]+f(i+1,1,k-1,dp,prices),f(i+1,0,k,dp,prices));
        }
    }
};