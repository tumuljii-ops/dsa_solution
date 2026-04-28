class Solution {
public:
    int longest(string s,string s1,int i,int j,vector<vector<int>>&dp){
            
            int n=s.length();
            if(i>=n || j>=n) return 0;

            if(dp[i][j]!=-1) return dp[i][j];

            int len=0;

            if(s[i]==s1[j]){
                len=1+longest(s,s1,i+1,j+1,dp);
            }
            else{
                 int skip1=longest(s,s1,i+1,j,dp);
                 int skip2=longest(s,s1,i,j+1,dp);

                 len=max(skip1,skip2);
            }

            return dp[i][j]=len;

    }
    int longestPalindromeSubseq(string s) {
          int n=s.length();
          string s1=s;
          reverse(s1.begin(),s1.end());
          vector<vector<int>>dp(n+1,vector<int>(n+1,0));

          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                 
                 if(s[i-1]==s1[j-1]){
                     dp[i][j]=1+dp[i-1][j-1];
                 }
                 else{
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
            }
          }

          return dp[n][n];
          
    }
};