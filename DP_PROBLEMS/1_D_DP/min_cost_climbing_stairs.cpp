class Solution {
public:
    int dp(int ind,vector<int>&cost,vector<int>&store){
           int size=cost.size();

           if(ind>=size) return 0;
           
           if(store[ind]!=-1) return store[ind];

           int a=cost[ind]+dp(ind+1,cost,store);
           int b=cost[ind]+dp(ind+2,cost,store);

          return store[ind]=min(a,b);
          
    }
    int minCostClimbingStairs(vector<int>& cost) {
           vector<int>store(cost.size()+1,-1);

           int num=dp(0,cost,store);
           int num1=dp(1,cost,store);

           return min(num,num1);
    }
};