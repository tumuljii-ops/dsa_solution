class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
          int m=grid.size();
          int n=grid[0].size();

          vector<vector<int>>mat(m,vector<int>(n,0));
          int pre1=0;
          int pre2=0;
          mat[0][0]=grid[0][0];

          for(int i=1;i<n;i++){
               mat[0][i]=mat[0][i-1]+grid[0][i];
          }

          for(int j=1;j<m;j++){
            mat[j][0]=mat[j-1][0]+grid[j][0];
          }

          for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]=grid[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
          }

          for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                 if(grid[i][j])
            }
          }







    }
};