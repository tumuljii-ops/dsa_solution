class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,vector<int>&cuts){
             
              if(i+1==j) return 0;

              if(dp[i][j]!=-1) return dp[i][j];

              int ans=INT_MAX;

              for(int k=i+1;k<j;k++){
                   
                  int cost=cuts[j]-cuts[i]+memo(i,k,dp,cuts)+memo(k,j,dp,cuts);

                  ans=min(ans,cost);
              }

            return dp[i][j]=ans;

    }
    int minCost(int n, vector<int>& cuts) {
           cuts.push_back(0);
           cuts.push_back(n);

           sort(cuts.begin(),cuts.end());

           int m=cuts.size();

           vector<vector<int>>dp(m,vector<int>(m,-1));

           return memo(0,m-1,dp,cuts);
    }
};