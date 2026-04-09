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

// ----------------------min cost climbing stairs ---------------

  int minCostClimbingStairs(vector<int>& cost) {
        
              int n = cost.size();
              vector<int> ans(n+1);

              ans[0] = 0;
              ans[1] = 0;

              for (int i = 2; i <= n; i++) {
                  int first_step = ans[i-1] + cost[i-1];
                int second_step = ans[i-2] + cost[i-2];

                 ans[i] = min(first_step, second_step);
                 }

    return ans[n];
    }
};