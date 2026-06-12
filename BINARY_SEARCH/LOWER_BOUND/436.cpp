class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
                
                 int n=intervals.size();

                 unordered_map<int,int>mpp;

                 for(int i=0;i<intervals.size();i++){
                       mpp[intervals[i][0]]=i;
                 }

                 vector<int>ans(n,-1);

                 vector<int>start;

                 for(int i=0;i<n;i++){
                       int a=intervals[i][0];
                       start.push_back(a);
                 }

                 sort(start.begin(),start.end());

                 for(int i=0;i<n;i++){
                     
                      int endpoint=intervals[i][1];

                      auto it=lower_bound(start.begin(),start.end(),endpoint);

                      if(it!=start.end()){
                        ans[i]=mpp[*it];
                      }
                 }

                 return ans;
    }
};