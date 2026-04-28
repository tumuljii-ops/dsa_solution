class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
           int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, false));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dis(m, vector<int>(n, 0));

        // Multi-source BFS (all 0's)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 
                if(isWater[i][j] == 1){
                    visited[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dis[row][col] = steps;

            // Up
            if(row-1 >= 0 && !visited[row-1][col]){
                visited[row-1][col] = true;
                q.push({{row-1,col},steps+1});
            }

            // Down
            if(row+1 < m && !visited[row+1][col]){
                visited[row+1][col] = true;
                q.push({{row+1,col},steps+1});
            }

            // Left
            if(col-1 >= 0 && !visited[row][col-1]){
                visited[row][col-1] = true;
                q.push({{row,col-1},steps+1});
            }

            // Right
            if(col+1 < n && !visited[row][col+1]){
                visited[row][col+1] = true;
                q.push({{row,col+1},steps+1});
            }
        }

        return dis;
    }
};