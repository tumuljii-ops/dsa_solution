class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int trans=2;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,dp,prices);
    }
    int f(int ind,int buy,int trans,vector<vector<vector<int>>>&dp,vector<int>&prices){
        if(ind==prices.size()||trans==0) return 0;
        if(dp[ind][buy][trans]!=-1) return dp[ind][buy][trans];
        if(buy==1){
            return dp[ind][buy][trans]=max(-prices[ind]+f(ind+1,0,trans,dp,prices),f(ind+1,1,trans,dp,prices));
        }
        else{
            return dp[ind][buy][trans]=max(prices[ind]+f(ind+1,1,trans-1,dp,prices),f(ind+1,0,trans,dp,prices));
        }
    }
};