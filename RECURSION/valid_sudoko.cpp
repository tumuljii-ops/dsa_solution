class Solution {
public:
    bool isfit(int row,int col,vector<vector<char>>& board){

        char c=board[row][col];

        // check row
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==c){
                return false;
            }
        }

        // check column
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==c){
                return false;
            }
        }

        // check 3x3 box
        int roww=(row/3)*3;
        int coll=(col/3)*3;

        for(int i=roww;i<roww+3;i++){
            for(int j=coll;j<coll+3;j++){
                if((i!=row || j!=col) && board[i][j]==c){
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){

                if(board[row][col] != '.'){
                    if(!isfit(row,col,board)){
                        return false;
                    }
                }

            }
        }

        return true;
    }
};