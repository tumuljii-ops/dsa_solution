class Solution {
public:

    void dfs(vector<vector<int>>& visited,
             vector<vector<int>>& grid,
             int row,
             int col,
             queue<pair<pair<int,int>,int>>& q)
    {
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = true;
        q.push({{row,col},0});

        if(row-1>=0 && grid[row-1][col]==1 && visited[row-1][col]==false){
            dfs(visited,grid,row-1,col,q);
        }

        if(row+1<n && grid[row+1][col]==1 && visited[row+1][col]==false){
            dfs(visited,grid,row+1,col,q);
        }

        if(col+1<m && grid[row][col+1]==1 && visited[row][col+1]==false){
            dfs(visited,grid,row,col+1,q);
        }

        if(col-1>=0 && grid[row][col-1]==1 && visited[row][col-1]==false){
            dfs(visited,grid,row,col-1,q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,false));

        queue<pair<pair<int,int>,int>> q;

        bool found = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    dfs(visited,grid,i,j,q);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;

            q.pop();

            if(row-1>=0 && visited[row-1][col]==false){

                if(grid[row-1][col]==1){
                    return dis;
                }

                q.push({{row-1,col},dis+1});
                visited[row-1][col]=true;
            }

            if(row+1<n && visited[row+1][col]==false){

                if(grid[row+1][col]==1){
                    return dis;
                }

                q.push({{row+1,col},dis+1});
                visited[row+1][col]=true;
            }

            if(col-1>=0 && visited[row][col-1]==false){

                if(grid[row][col-1]==1){
                    return dis;
                }

                q.push({{row,col-1},dis+1});
                visited[row][col-1]=true;
            }

            if(col+1<m && visited[row][col+1]==false){

                if(grid[row][col+1]==1){
                    return dis;
                }

                q.push({{row,col+1},dis+1});
                visited[row][col+1]=true;
            }
        }

        return -1;
    }
};