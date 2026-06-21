class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
           
           map<vector<int>,int> mpp;

            int n=grid.size();
            int m=grid[0].size();

            for(int i=0;i<n;i++){
                
                 vector<int>ans;

                 for(int j=0;j<m;j++){
                     ans.push_back(grid[i][j]);
                 }

                 mpp[ans]++;
            }

            int total=0;

            for(int j=0;j<m;j++){
                  
                  vector<int>ans;

                  for(int i=0;i<n;i++){
                      
                      ans.push_back(grid[i][j]);
                  }

                  if(mpp.find(ans)!=mpp.end()){
                      total=total+mpp[ans];
                  }
            }

            return total;
    }
};