class Solution {
public:
    int memo(vector<vector<int>>&pairs,vector<vector<int>>&dp,int ind,int prev){
          
           if(ind==pairs.size()) return 0;

           if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];


           int skip=memo(pairs,dp,ind+1,prev);
           int take=0;

           if(prev==-1|| pairs[ind][0]>pairs[prev][1]){
               
                 take=1+memo(pairs,dp,ind+1,ind);
           }

           return dp[ind][prev+1]=max(take,skip);


    }
    int findLongestChain(vector<vector<int>>& pairs) {
              
              sort(pairs.begin(),pairs.end());
              int n=pairs.size();

              vector<vector<int>>dp(n,vector<int>(n+1,-1));

              int len=memo(pairs,dp,0,-1);

              return len;
    }
};