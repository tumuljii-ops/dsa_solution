class Solution {
public:
    bool valid(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, string res, int row, int col) {
        int n = board.size();
        int m = board[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] == true) {
            return false;
        }

        if (res.size() >= word.size()) {
            return false;
        }

        if (board[row][col] != word[res.size()]) {
            return false;
        }

        res = res + board[row][col];

        if (res == word) {
            return true;
        }

        visited[row][col] = true;
        bool found = false;

        if (valid(board, visited, word, res, row + 1, col)) {
            found = true;
        }
        else if (valid(board, visited, word, res, row - 1, col)) {
            found = true;
        }
        else if (valid(board, visited, word, res, row, col + 1)) {
            found = true;
        }
        else if (valid(board, visited, word, res, row, col - 1)) {
            found = true;
        }

        visited[row][col] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        string res = "";

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (valid(board, visited, word, res, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};