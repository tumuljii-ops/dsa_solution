class Solution {
public:
    int memo(int row,int col,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
           int m=obstacleGrid.size();
           int n=obstacleGrid[0].size();
           
           if(row>=m || col>=n|| obstacleGrid[row][col]==1) return 0;

           if(row==m-1 && col==n-1) return 1;

           if(dp[row][col]!=-1) return dp[row][col];

           int down=memo(row+1,col,dp,obstacleGrid);
           int right=memo(row,col+1,dp,obstacleGrid);

           return dp[row][col]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int row=0;
         int col=0;
         int m=obstacleGrid.size();
         int n=obstacleGrid[0].size();
         if (obstacleGrid[0][0] == 1) return 0;

         vector<vector<int>>dp(m,vector<int>(n,0));
         dp[0][0]=1;

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 
                 if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                 }
                 if(i==0 && j==0) continue;

                int down=0;
                int right=0;

                if(i>0) down=dp[i-1][j];
                if(j>0) right=dp[i][j-1];

                dp[i][j]=down+right;

            }
         }

         return dp[m-1][n-1];

    }
};