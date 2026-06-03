class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        queue<pair<pair<int,int>,int>> q;

        int i = entrance[0];
        int j = entrance[1];

        q.push({{i,j},0});

        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> visited(n,vector<int>(m,false));
        visited[i][j] = true;

        int ans = INT_MAX;

        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            if((row==0 || col==0 || row==n-1 || col==m-1) &&
               !(row==entrance[0] && col==entrance[1]))
            {
                ans = min(ans,dis);
                return ans;
            }

            if(row-1 >= 0 && maze[row-1][col] != '+' &&
               visited[row-1][col] == false)
            {
                q.push({{row-1,col},dis+1});
                visited[row-1][col] = true;
            }

            if(row+1 < n && maze[row+1][col] != '+' &&
               visited[row+1][col] == false)
            {
                q.push({{row+1,col},dis+1});
                visited[row+1][col] = true;
            }

            if(col-1 >= 0 && maze[row][col-1] != '+' &&
               visited[row][col-1] == false)
            {
                q.push({{row,col-1},dis+1});
                visited[row][col-1] = true;
            }

            if(col+1 < m && maze[row][col+1] != '+' &&
               visited[row][col+1] == false)
            {
                q.push({{row,col+1},dis+1});
                visited[row][col+1] = true;
            }
        }

        return -1;
    }
};