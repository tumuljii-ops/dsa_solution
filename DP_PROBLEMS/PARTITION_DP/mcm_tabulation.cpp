int matrixMultiplication(vector<int>& arr)
{
    int n = arr.size();

    // dp[i][j]
    // minimum cost to multiply matrices from i to j

    vector<vector<int>> dp(n, vector<int>(n, 0));

    //------------------------------------------------
    // Base Case
    //------------------------------------------------

    // dp[i][i] = 0 already
    // because single matrix requires no multiplication

    //------------------------------------------------
    // Fill interval lengths from small to large
    //------------------------------------------------

    // len = number of matrices in current interval

    for(int len = 2; len < n; len++)
    {
        //------------------------------------------------
        // Generate all intervals of this length
        //------------------------------------------------

        for(int i = 1; i <= n - len; i++)
        {
            int j = i + len - 1;

            // We want minimum cost
            dp[i][j] = INT_MAX;

            //------------------------------------------------
            // Try every partition point
            //------------------------------------------------

            for(int k = i; k < j; k++)
            {
                //------------------------------------------------
                // Left interval
                //------------------------------------------------

                int left = dp[i][k];

                //------------------------------------------------
                // Right interval
                //------------------------------------------------

                int right = dp[k+1][j];

                //------------------------------------------------
                // Cost of final multiplication
                //------------------------------------------------

                int multiplyCost =
                arr[i-1] * arr[k] * arr[j];

                //------------------------------------------------
                // Total cost if partition is at k
                //------------------------------------------------

                int total =
                left +
                right +
                multiplyCost;

                dp[i][j] =
                min(dp[i][j], total);
            }
        }
    }

    //------------------------------------------------
    // Whole answer
    //------------------------------------------------

    return dp[1][n-1];
}