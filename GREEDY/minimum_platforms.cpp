class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
         int n=arr.size();
         
         vector<pair<int,int>>vec;
         
         for(int i=0;i<n;i++){
              
              vec.push_back({arr[i],dep[i]});
         }
         
         
         sort(vec.begin(),vec.end());
         
         priority_queue<int,vector<int>,greater<int>>pq;
         pq.push(vec[0].second);
         
         int ans=1;
         
         
         for(int i=1;i<n;i++){
              
              if(pq.top()<vec[i].first){
                    pq.pop();
              }
              
              pq.push(vec[i].second);
              
              ans=max(ans,(int)pq.size());
         }
         
         return ans;
    }
};
