class Solution {
public:
    int lcs(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
           int n1=nums1.size();
           int n2=nums2.size();
           
           if(i>=n1 || j>=n2) return 0;

           if(dp[i][j]!=-1) return dp[i][j];

           int total=0;

           if(nums1[i]==nums2[j]){
             total=1+lcs(i+1,j+1,nums1,nums2,dp);
           }
           else{
               int skip1=lcs(i+1,j,nums1,nums2,dp);
               int skip2=lcs(i,j+1,nums1,nums2,dp);
               total=max(skip1,skip2);
           }

           return dp[i][j]=total;
          
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
            int n1=nums1.size();
            int n2=nums2.size();
            
            vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){

                      if(nums1[i-1]==nums2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                      }
                      else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                      }
                }
            }

            return dp[n1][n2];
    }
};