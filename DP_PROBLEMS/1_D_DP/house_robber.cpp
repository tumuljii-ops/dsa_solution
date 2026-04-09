class Solution {
public:
    int memo(int ind,vector<int>&nums,vector<int>&dp){
        int size=nums.size();
         if(ind>=size) return 0;

         if(dp[ind]!=-1) return dp[ind];

         int a=nums[ind]+memo(ind+2,nums,dp);
         int b=nums[ind]+memo(ind+3,nums,dp);

         return dp[ind]=max(a,b);
    }
    int rob(vector<int>& nums) {
          int n=nums.size();
          vector<int>dp(n+1,-1);

          int a=memo(0,nums,dp);
          int b=memo(1,nums,dp);

          return max(a,b);
    }
};
// tabulation -------------------
int rob(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n + 3, 0);  // extra space for i+2, i+3

    for (int i = n - 1; i >= 0; i--) {
        int a = nums[i] + dp[i + 2];
        int b = nums[i] + dp[i + 3];

        dp[i] = max(a, b);
    }

    return max(dp[0], dp[1]);
}
};