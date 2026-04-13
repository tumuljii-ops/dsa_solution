class Solution {
public:
    int memo(vector<int>&days,vector<int>&costs,vector<int>&dp,int ind){
          int n=days.size();
          if(ind>=n) return 0;

          if(dp[ind]!=-1) return dp[ind];
          
          int cost=0;

          cost=cost+costs[0]+memo(days,costs,dp,ind+1);

          int index=ind;
          while(index<n && days[index]<days[ind]+7){
             index++;
          }
          int cost1=0;
          
          cost1=cost1+costs[1]+memo(days,costs,dp,index);

          int indd=ind;

          while(indd<n && days[indd]<days[ind]+30){
             indd++;
          }
          int cost2=0;

          cost2=cost2+costs[2]+memo(days,costs,dp,indd);

          return dp[ind]=min(cost,min(cost1,cost2));


    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
          int n=days.size();
          vector<int>dp(n+1,-1);

          return memo(days,costs,dp,0);
    }
};