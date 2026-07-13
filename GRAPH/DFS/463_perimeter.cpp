class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 1;

        if(visited[i][j])
            return 0;

        visited[i][j] = 1;

        int perim = 0;
        perim += dfs(i + 1, j, grid, visited);
        perim += dfs(i - 1, j, grid, visited);
        perim += dfs(i, j + 1, grid, visited);
        perim += dfs(i, j - 1, grid, visited);

        return perim;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    return dfs(i, j, grid, visited);
            }
        }
        return 0;
    }
};