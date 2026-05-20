class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int n=prices.size();

          vector<vector<int>>dp(n,vector<int>(2,-1));

        /*  for(int i=n-1;i>=0;i--){
             
              for(int j=0;j<=1;j--){
                   
                   if(j==1){
                      profit=max(-prices[j]+dp[i+1][0],dp[i+1][1]);
                   }
                   else{
                      profit=max(prices[j]+dp[i+1][1],dp[i+1][0]);
                   }
              }

              dp[i]=profit;
          }*/





          return f(0,1,dp,prices);
    }

    int f(int ind,int buy,vector<vector<int>>&dp,vector<int>&prices){
           
           if(ind==prices.size()){
                return 0;
           }

           if(dp[ind][buy]!=-1) return dp[ind][buy];
           int profit=0;

           if(buy){
               
                profit=max(-prices[ind]+f(ind+1,0,dp,prices),f(ind+1,1,dp,prices));
           }
           else{
              profit=max(prices[ind]+f(ind+1,1,dp,prices),f(ind+1,0,dp,prices));
           }

           return dp[ind][buy]=profit;
    }
};