class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         vector<vector<int>>countX(n,vector<int>(m,0));
         vector<vector<int>>countY(n,vector<int>(m,0));
         int count_x=0;
         
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    break;
                }
                else{
                    count_x++;
                }
            }
         }
         if(grid[0][0]=='X') countX[0][0]=1;
         if(grid[0][0]=='Y') countY[0][0]=1;

         for(int i=1;i<n;i++){
             if(grid[i][0]=='X'){
                countX[i][0]=countX[i-1][0]+1;
                countY[i][0]=countY[i-1][0];
             }
             else if(grid[i][0]=='Y'){
                countX[i][0]=countX[i-1][0];
                countY[i][0]=countY[i-1][0]+1;
             }
             else if(grid[i][0]=='.'){
                countX[i][0]=countX[i-1][0];
                countY[i][0]=countY[i-1][0];
             }
         }

         for(int j=1;j<m;j++){
            if(grid[0][j]=='X'){
                countX[0][j]=countX[0][j-1]+1;
                countY[0][j]=countY[0][j-1];
            }
            else if(grid[0][j]=='Y'){
                countY[0][j]=countY[0][j-1]+1;
                countX[0][j]=countX[0][j-1];
            }
            else if(grid[0][j]=='.'){
                countY[0][j]=countY[0][j-1];
                countX[0][j]=countX[0][j-1];
            }
         }

         for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                 if(grid[i][j]=='X'){
                    countX[i][j]=countX[i-1][j]+countX[i][j-1]-countX[i-1][j-1]+1;
                    countY[i][j]=countY[i-1][j]+countY[i][j-1]-countY[i-1][j-1];
                 }
                 else if(grid[i][j]=='Y'){
                    countY[i][j]=countY[i-1][j]+countY[i][j-1]-countY[i-1][j-1]+1;
                    countX[i][j]=countX[i-1][j]+countX[i][j-1]-countX[i-1][j-1];
                 }
                 else if(grid[i][j]=='.'){
                    countY[i][j]=countY[i-1][j]+countY[i][j-1]-countY[i-1][j-1];
                    countX[i][j]=countX[i-1][j]+countX[i][j-1]-countX[i-1][j-1];
                 }
            }
         }

         int count=0;

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(countX[i][j]==countY[i][j] && countX[i][j]>0){
                    count++;
                }
            }
         }

         if(count_x==m*n) return 0;
         else return count;

       
    }
};

