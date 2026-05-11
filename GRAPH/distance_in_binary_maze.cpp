class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        int n = grid.size();
        int m = grid[0].size();
                
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
                
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
                
        pq.push({0, {source.first, source.second}});
                
        dis[source.first][source.second] = 0;
        
        while(!pq.empty()) {
             
            auto top = pq.top();
            pq.pop();
             
            int d = top.first;
            int i = top.second.first;
            int j = top.second.second;
             
            // Down
            if(i + 1 < n && grid[i+1][j] == 1 &&
               dis[i+1][j] > d + 1) {
                   
                dis[i+1][j] = d + 1;
                pq.push({d + 1, {i+1, j}});
            }
             
            // Up
            if(i - 1 >= 0 && grid[i-1][j] == 1 &&
               dis[i-1][j] > d + 1) {
                   
                dis[i-1][j] = d + 1;
                pq.push({d + 1, {i-1, j}});
            }
             
            // Right
            if(j + 1 < m && grid[i][j+1] == 1 &&
               dis[i][j+1] > d + 1) {
                   
                dis[i][j+1] = d + 1;
                pq.push({d + 1, {i, j+1}});
            }
             
            // Left
            if(j - 1 >= 0 && grid[i][j-1] == 1 &&
               dis[i][j-1] > d + 1) {
                   
                dis[i][j-1] = d + 1;
                pq.push({d + 1, {i, j-1}});
            }
        }
        
        if(dis[destination.first][destination.second] == INT_MAX)
            return -1;
            
        return dis[destination.first][destination.second];
    }
};