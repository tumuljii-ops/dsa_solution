class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int startRow = 0;
        int startCol = 0;

        // Find starting position and count total keys
        int totalKeys = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '@') {
                    startRow = i;
                    startCol = j;
                }

                // Keys are a,b,c,d,e,f
                if(islower(grid[i][j])) {
                    totalKeys = max(totalKeys,
                                    grid[i][j] - 'a' + 1);
                }
            }
        }

        // Example:
        // totalKeys = 3
        // finalMask = 111 (binary) = 7
        // means we have collected all keys
        int finalMask = (1 << totalKeys) - 1;

        // Queue stores:
        // row, col, mask, distance
        queue<vector<int>> q;

        q.push({startRow, startCol, 0, 0});

        // visited[row][col][mask]
        //
        // Why?
        //
        // Reaching (2,3) with no keys
        // is different from
        // reaching (2,3) with keys {a,b}
        //
        // Therefore row+col alone is NOT enough.
        vector<vector<vector<int>>> visited(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << totalKeys, 0)
            )
        );

        visited[startRow][startCol][0] = 1;

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            int row  = top[0];
            int col  = top[1];
            int mask = top[2];
            int dist = top[3];

            // If all keys collected
            if(mask == finalMask) {
                return dist;
            }

            // ==========================
            // MOVE UP
            // ==========================
            if(row - 1 >= 0 && grid[row - 1][col] != '#') {

                int newMask = mask;

                char ch = grid[row - 1][col];

                // If current cell is a key
                if(islower(ch)) {
                    newMask |= (1 << (ch - 'a'));
                }

                // If current cell is a lock
                if(isupper(ch)) {

                    int neededKey = ch - 'A';

                    // Don't have key
                    if((mask & (1 << neededKey)) == 0) {
                        goto DOWN;
                    }
                }

                if(!visited[row - 1][col][newMask]) {

                    visited[row - 1][col][newMask] = 1;

                    q.push({
                        row - 1,
                        col,
                        newMask,
                        dist + 1
                    });
                }
            }

DOWN:

            // ==========================
            // MOVE DOWN
            // ==========================
            if(row + 1 < n && grid[row + 1][col] != '#') {

                int newMask = mask;

                char ch = grid[row + 1][col];

                if(islower(ch)) {
                    newMask |= (1 << (ch - 'a'));
                }

                if(isupper(ch)) {

                    int neededKey = ch - 'A';

                    if((mask & (1 << neededKey)) == 0) {
                        goto LEFT;
                    }
                }

                if(!visited[row + 1][col][newMask]) {

                    visited[row + 1][col][newMask] = 1;

                    q.push({
                        row + 1,
                        col,
                        newMask,
                        dist + 1
                    });
                }
            }

LEFT:

            // ==========================
            // MOVE LEFT
            // ==========================
            if(col - 1 >= 0 && grid[row][col - 1] != '#') {

                int newMask = mask;

                char ch = grid[row][col - 1];

                if(islower(ch)) {
                    newMask |= (1 << (ch - 'a'));
                }

                if(isupper(ch)) {

                    int neededKey = ch - 'A';

                    if((mask & (1 << neededKey)) == 0) {
                        goto RIGHT;
                    }
                }

                if(!visited[row][col - 1][newMask]) {

                    visited[row][col - 1][newMask] = 1;

                    q.push({
                        row,
                        col - 1,
                        newMask,
                        dist + 1
                    });
                }
            }

RIGHT:

            // ==========================
            // MOVE RIGHT
            // ==========================
            if(col + 1 < m && grid[row][col + 1] != '#') {

                int newMask = mask;

                char ch = grid[row][col + 1];

                if(islower(ch)) {
                    newMask |= (1 << (ch - 'a'));
                }

                if(isupper(ch)) {

                    int neededKey = ch - 'A';

                    if((mask & (1 << neededKey)) == 0) {
                        continue;
                    }
                }

                if(!visited[row][col + 1][newMask]) {

                    visited[row][col + 1][newMask] = 1;

                    q.push({
                        row,
                        col + 1,
                        newMask,
                        dist + 1
                    });
                }
            }
        }

        return -1;
    }
};