class Solution {
public:
    int mini_sum(vector<vector<int>>&dp,vector<vector<int>>&grid,int i ,int j){
           
           int n=grid.size();
           int m=grid[0].size();

           if(i>=n || j>=m) return INT_MAX;

           if(i==n-1 && j==m-1) return grid[i][j];

           if(dp[i][j]!=-1) return dp[i][j];

           int right=mini_sum(dp,grid,i+1,j);
           int down=mini_sum(dp,grid,i,j+1);

           int ans=min(right,down)+grid[i][j];

           return dp[i][j]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
          int n=grid.size();
          int m=grid[0].size();

          vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

          return mini_sum(dp,grid,0,0);
    }
};