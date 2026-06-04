class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> visited(n, vector<int>(n, false));

        visited[0][0] = true;

        queue<pair<pair<int,int>,int>> q;

        q.push({{0,0},1});

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            int row = top.first.first;
            int col = top.first.second;
            int dist = top.second;

            if(row == n-1 && col == n-1)
                return dist;

            // up
            if(row-1 >= 0 && grid[row-1][col] == 0 &&
               !visited[row-1][col]) {
                visited[row-1][col] = true;
                q.push({{row-1,col},dist+1});
            }

            // down
            if(row+1 < n && grid[row+1][col] == 0 &&
               !visited[row+1][col]) {
                visited[row+1][col] = true;
                q.push({{row+1,col},dist+1});
            }

            // left
            if(col-1 >= 0 && grid[row][col-1] == 0 &&
               !visited[row][col-1]) {
                visited[row][col-1] = true;
                q.push({{row,col-1},dist+1});
            }

            // right
            if(col+1 < n && grid[row][col+1] == 0 &&
               !visited[row][col+1]) {
                visited[row][col+1] = true;
                q.push({{row,col+1},dist+1});
            }

            // down-right
            if(row+1 < n && col+1 < n &&
               grid[row+1][col+1] == 0 &&
               !visited[row+1][col+1]) {
                visited[row+1][col+1] = true;
                q.push({{row+1,col+1},dist+1});
            }

            // down-left
            if(row+1 < n && col-1 >= 0 &&
               grid[row+1][col-1] == 0 &&
               !visited[row+1][col-1]) {
                visited[row+1][col-1] = true;
                q.push({{row+1,col-1},dist+1});
            }

            // up-right
            if(row-1 >= 0 && col+1 < n &&
               grid[row-1][col+1] == 0 &&
               !visited[row-1][col+1]) {
                visited[row-1][col+1] = true;
                q.push({{row-1,col+1},dist+1});
            }

            // up-left
            if(row-1 >= 0 && col-1 >= 0 &&
               grid[row-1][col-1] == 0 &&
               !visited[row-1][col-1]) {
                visited[row-1][col-1] = true;
                q.push({{row-1,col-1},dist+1});
            }
        }

        return -1;
    }
};