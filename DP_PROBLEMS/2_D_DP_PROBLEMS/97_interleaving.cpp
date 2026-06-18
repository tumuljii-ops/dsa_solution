class Solution {
public:
    bool solve(int i,int j,string s1,string s2,string s3,vector<vector<int>>&dp){
         
            int len1=s1.length();
            int len2=s2.length();

            if(i>=len1 && j>=len2){
                 return true;
            }

            if(dp[i][j]!=-1) return dp[i][j];

            bool ans=false;

            if(i<len1 && s1[i]==s3[i+j]){
                ans|=solve(i+1,j,s1,s2,s3,dp);
            }

            if(j<len2 && s2[j]==s3[i+j]){
                 ans|=solve(i,j+1,s1,s2,s3,dp);

            }

            return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
           
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 + n2 != s3.size())
            return false;

        vector<vector<int>> dp(n1 + 1,
                               vector<int>(n2 + 1, -1));

        return solve(0, 0, s1, s2, s3, dp);
    }
};