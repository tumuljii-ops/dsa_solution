class Solution {
    int lps(string&s,string&s2){
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++) dp[i][n]=0;
        for(int i=0;i<n;i++) dp[n][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestpalsubs(string &s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return lps(s,s2);
    }
public:
    int minInsertions(string s) {
        int n=s.length();
        return n-longestpalsubs(s);
    }
};