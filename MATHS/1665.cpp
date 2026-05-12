class Solution {
public:
     static bool cmp(vector<int>&a,vector<int>&b){
                 
                  return (a[1]-a[0])>(b[1]-b[0]);
          }
    int minimumEffort(vector<vector<int>>& tasks) {
         
         
         sort(tasks.begin(),tasks.end(),cmp);

         int curr=0;
         int ans=0;

         for(auto &it:tasks){
              int actual=it[0];
              int minimum=it[1];

              if(curr<minimum){
                  ans=ans+(minimum-curr);
                  curr=minimum;
              }

              curr=curr-actual;
         }

         return ans;
    }
};