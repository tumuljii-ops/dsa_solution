class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
          int mod=12345;
          int row=grid.size();
          int col=grid[0].size();
          int total=row*col;

          vector<int>prefix(total,1);
          vector<int>suffix(total,1);
          vector<int>ans(total);

          for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                 ans.push_back(grid[i][j]%mod);
            }
          }

          for(int i=1;i<total;i++){
               long long res=1LL*prefix[i-1]*ans[i-1];
               prefix[i]=res%mod;
          }

          for(int i=total-2;i>=0;i--){
            long long res1=1LL*suffix[i+1]*ans[i+1];
            suffix[i]=res1%mod;
          }

          vector<vector<int>>store(row,vector<int>(col,0));

          for(int i=0;i<total;i++){
               long long prod=1LL*prefix[i]*suffix[i];
               int n=i/row;
               int m=i%row;
               
               store[n][m]=prod % mod;

          }

          return store;
    }
};