class Solution {
    int minpath(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& arr) {
        int m = arr.size();
        if (i == m - 1) return arr[m - 1][j];
        if (dp[i][j] != -1) return dp[i][j];

        int down = arr[i][j] + minpath(i + 1, j, dp, arr);
        int diag = arr[i][j] + minpath(i + 1, j + 1, dp, arr);

        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<int>dp(triangle[n-1]);
       for(int i=n-2;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
        }
       }
       return dp[0];
    }
};
