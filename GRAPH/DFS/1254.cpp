class Solution {
public:

    bool dfs(int row,int col,vector<vector<int>>& grid,
             vector<vector<int>>& visited){

        int n=grid.size();
        int m=grid[0].size();

        visited[row][col]=true;

        // If land reaches boundary,
        // island cannot be closed
        bool isClosed=true;

        if(row==0 || row==n-1 || col==0 || col==m-1){
            isClosed=false;
        }

        // UP
        if(row-1>=0 &&
           grid[row-1][col]==0 &&
           !visited[row-1][col]){

            isClosed &= dfs(row-1,col,grid,visited);
        }

        // DOWN
        if(row+1<n &&
           grid[row+1][col]==0 &&
           !visited[row+1][col]){

            isClosed &= dfs(row+1,col,grid,visited);
        }

        // LEFT
        if(col-1>=0 &&
           grid[row][col-1]==0 &&
           !visited[row][col-1]){

            isClosed &= dfs(row,col-1,grid,visited);
        }

        // RIGHT
        if(col+1<m &&
           grid[row][col+1]==0 &&
           !visited[row][col+1]){

            isClosed &= dfs(row,col+1,grid,visited);
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(
            n,
            vector<int>(m,false)
        );

        int count=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(grid[i][j]==0 &&
                   !visited[i][j]){

                    if(dfs(i,j,grid,visited)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};