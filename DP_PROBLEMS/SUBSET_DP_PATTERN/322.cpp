class Solution {
public:
    int memo(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp) {
           
        int n = coins.size();

        if (amount == 0) return 0;

        if (ind == n) return 1e9;  

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = 1e9;

        if (coins[ind] <= amount) {
            take = 1 + memo(coins, amount - coins[ind], ind, dp);
        }

        int nottake = memo(coins, amount, ind + 1, dp);

        return dp[ind][amount] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();

        vector<vector<int>>tab(n+1,vector<int>(amount+1,1e9));
        
        for(int i=0;i<=n;i++){
            tab[i][0]=0;
        }

        for(int i=n-1;i>=0;i--){
            for(int amt=1;amt<=amount;amt++){
                  
                   int nottake=tab[i+1][amt];
                   int take=1e9;

                   if(coins[i]<=amt){
                    take=1+tab[i][amount-coins[i]];
                   }

                   tab[i][amt]=min(take,nottake);
            }
        }
        
        int ans=tab[0][amount];

        if(ans>=1e9) return -1;
        else return ans;
        
    }
};
