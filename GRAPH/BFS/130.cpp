class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<char>> store = board;  

        queue<pair<int,int>> q;

        // push boundary 'O'
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || j == 0 || i == row-1 || j == col-1){
                    if(board[i][j] == 'O'){
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }

        // BFS
        while(!q.empty()){
            int row1 = q.front().first;
            int col1 = q.front().second;
            q.pop();

            if(row1-1 >= 0 && !visited[row1-1][col1] && board[row1-1][col1] == 'O'){
                visited[row1-1][col1] = true;
                q.push({row1-1, col1});
            }

            if(row1+1 < row && !visited[row1+1][col1] && board[row1+1][col1] == 'O'){
                visited[row1+1][col1] = true;
                q.push({row1+1, col1});
            }

            if(col1-1 >= 0 && !visited[row1][col1-1] && board[row1][col1-1] == 'O'){
                visited[row1][col1-1] = true;
                q.push({row1, col1-1});
            }

           
            if(col1+1 < col && !visited[row1][col1+1] && board[row1][col1+1] == 'O'){
                visited[row1][col1+1] = true;
                q.push({row1, col1+1});
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    store[i][j] = 'X';
                }
            }
        }

        // copy back to board
        board = store;
    }
};
