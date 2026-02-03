class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,pair<int,int>>,
                      vector<pair<int,pair<int,int>>>,
                      greater<pair<int,pair<int,int>>>>pq;
        

         for(int i=0;i<points.size();i++){
             int dist1=points[i][0]*points[i][0];
             int dist2=points[i][1]*points[i][1];

             int destination=(dist1+dist2);

             pq.push({destination,{points[i][0],points[i][1]}});


         }

         vector<vector<int>>ans;

         while(k>0){
              auto top=pq.top();

              ans.push_back({top.second.first,top.second.second});
              pq.pop();

              k--;

         }
        
        return ans;
    }
};