class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<pair<int,int>> dir = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int live = 0;

                for(auto &d : dir) {
                    int nr = i + d.first;
                    int nc = j + d.second;

                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       abs(board[nr][nc]) == 1) {
                        live++;
                    }
                }

                if(board[i][j] == 1) {

                    if(live < 2 || live > 3)
                        board[i][j] = -1;   // alive -> dead
                }
                else {

                    if(live == 3)
                        board[i][j] = 2;    // dead -> alive
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == -1)
                    board[i][j] = 0;

                if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};