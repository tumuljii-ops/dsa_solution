class Solution {
public:
    
    void dfs(int r, int c, int baseR, int baseC,
             vector<vector<int>>& grid,
             vector<vector<int>>& visited,
             vector<pair<int,int>>& shape) {
        
        int n = grid.size();
        int m = grid[0].size();

        visited[r][c] = 1;

        // store relative position
        shape.push_back({r - baseR, c - baseC});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               !visited[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, baseR, baseC, grid, visited, shape);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(!visited[i][j] && grid[i][j] == 1) {
                    
                    vector<pair<int,int>> shape;

                    dfs(i, j, i, j, grid, visited, shape);

                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};
