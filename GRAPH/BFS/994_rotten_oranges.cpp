class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
           int n = grid.size();
           int m = grid[0].size();

           vector<vector<bool>> visited(n, vector<bool>(m, false));

           queue<pair<pair<int,int>,int>> q; // {(i,j),time}

           for(int i = 0; i < n; i++){
               for(int j = 0; j < m; j++){
                    
                    if(grid[i][j] == 2){
                        q.push({{i,j},0});
                        visited[i][j] = true;     
                    }
               }
           }

           int ans = 0;

           while(!q.empty()){
               int row = q.front().first.first;
               int col = q.front().first.second;
               int time = q.front().second;
                    
               ans = max(ans, time);
               q.pop();

               if(row-1 >= 0 && visited[row-1][col] == false && grid[row-1][col] == 1){
                   visited[row-1][col] = true;
                   q.push({{row-1,col}, time+1});
               }

               if(row+1 < n && visited[row+1][col] == false && grid[row+1][col] == 1){
                   visited[row+1][col] = true;
                   q.push({{row+1,col}, time+1});
               }

               if(col-1 >= 0 && visited[row][col-1] == false && grid[row][col-1] == 1){
                   visited[row][col-1] = true;
                   q.push({{row,col-1}, time+1});
               }

               if(col+1 < m && visited[row][col+1] == false && grid[row][col+1] == 1){
                   visited[row][col+1] = true;
                   q.push({{row,col+1}, time+1});
               }
           }

           for(int i = 0; i < n; i++){
               for(int j = 0; j < m; j++){
                   if(!visited[i][j] && grid[i][j] == 1) return -1;
               }
           }

           return ans;
    }
};
