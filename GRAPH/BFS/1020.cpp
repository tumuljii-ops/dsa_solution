class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()){
                
                int row=q.front().first;
                int col=q.front().second;

                if(row-1>=0 && visited[row-1][col]!=true && grid[row-1][col]==1){
                      visited[row-1][col]=true;
                      q.push({row-1,col});
                }

                if(row+1<n && visited[row+1][col]!=true && grid[row+1][col]==1){
                      visited[row+1][col]=true;
                      q.push({row+1,col});
                }

                if(col+1<m && visited[row][col+1]!=true && grid[row][col+1]==1){
                      visited[row][col+1]=true;
                      q.push({row,col+1});
                }

                if(col-1>=0 && visited[row][col-1]!=true && grid[row][col-1]==1){
                     visited[row][col-1]=true;
                     q.push({row,col-1});
                }
                
        }

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(visited[i][j]==false && grid[i][j]==1){
                    count++;
                  }
            }
        }

        return count;
    }
};
