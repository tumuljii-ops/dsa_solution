class Solution {
public:
    int fib(int number,vector<int>&dp){
        

         if(number<0) return 0;
         if(number==0) return 1;

         if(dp[number]!=-1) return dp[number];

         dp[number]=fib(number-1,dp)+fib(number-2,dp);

         return dp[number];        
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);

        int total=fib(n,dp);

        return total;
    }
};


//---------------tabulation---------------
   int climbStairs(int n) {

        //int total=fib(n,dp);

        vector<int>tab(n+1,-1);
        tab[0]=1;
        tab[1]=1;


        for(int i=2;i<=n;i++){
            tab[i]=tab[i-1]+tab[i-2];
        }

        return tab[n];
    }
};