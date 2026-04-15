class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&matrix){
             int n=matrix.size();
            
             if(j<0 || j>=n) return INT_MAX;
            // int n=matrix.size();

             if(i==n-1) return matrix[i][j];

             //if(i>=n || j>=n) return INT_MAX;

             if(dp[i][j]!=-1) return dp[i][j];

             int down=memo(i+1,j,dp,matrix);
             int right=memo(i+1,j+1,dp,matrix);
             int left=memo(i+1,j-1,dp,matrix);

             int ans=matrix[i][j]+min(down,min(right,left));

             return dp[i][j]=ans;
      
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
           
          int n = matrix.size();
          vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j = 0; j < n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){

                int down = dp[i+1][j];
                int left = (j > 0) ? dp[i+1][j-1] : INT_MAX;
                int right = (j < n-1) ? dp[i+1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(down, min(left, right));
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[0][j]);
        }

        return ans;

    }
};