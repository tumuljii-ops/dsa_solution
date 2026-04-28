class Solution {
public:
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int d = 0; d < 4; d++){
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == grid[i][j]){

                if(!vis[ni][nj]){
                    if(dfs(ni, nj, i, j, grid, vis)) return true;
                }
                else if(ni != pi || nj != pj){
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    if(dfs(i, j, -1, -1, grid, vis)) return true;
                }
            }
        }

        return false;
    }
};
