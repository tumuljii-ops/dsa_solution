class Solution {
  public:
  
    const int mod=1e9+7;
  
    int memo(int x,int y,vector<vector<int>>&dp){
         
          if(x==0 && y==0){
               return 1;
          }
          
          if(x<0 || y<0){
               return 0;
          }
          
          if(dp[x][y]!=-1) return dp[x][y];
          
          int take1=memo(x-1,y,dp);
          int take2=memo(x,y-1,dp);
          
          return dp[x][y]=(take1+take2)%mod;
    }
    int ways(int x, int y) {
        // code here
        
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        
        int z= memo(x,y,dp);
        
        return z%mod;
    }
};