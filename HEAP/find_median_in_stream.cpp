class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
           
             int n=grid.size();
             int m=grid[0].size();

             vector<vector<int>>ans(n,vector<int>(m,0));

             ans[0][0]=grid[0][0];

             for(int i=1;i<n;i++){
                 
                  ans[0][i]=ans[0][i-1]+grid[0][i];
             }

             for(int j=1;j<m;j++){
                  ans[j][0]=ans[j-1][0]+grid[j][0];
             }


             for(int i=1;i<n;i++){
                  
                  for(int j=1;j<m;j++){
                       
                        ans[i][j]=ans[i-1][j]+ans[i][j-1]+grid[i][j]-ans[i-1][j-1];
                      
                  }
             }

             vector<vector<int>>ans1(n,vector<int>(m,0));

             if(grid[0][0]==0){
                 ans1[0][0]=1;
             }
             else{
                 ans1[0][0]=0;
             }

             for(int i=1;i<n;i++){
                 
                   if(grid[0][i]==0){
                        ans1[0][i]=ans1[0][i-1]+1;
                   }
                   else{
                      ans1[0][i]=ans1[0][i-1];
                   }
             }

             for(int j=1;j<m;j++){
                   if(grid[0][j]==0){
                        ans1[j][0]=ans1[j-1][0]+1;
                   }
                   else{
                      ans1[j][0]=ans1[j-1][0];
                   }
                   
             }

             for(int i=1;i<n;i++){
                 for(int j=1;j<m;j++){
                     
                     if(grid[i][j]==0){
                         ans1[i][j]=ans1[i-1][j]+ans1[i][j-1]+1-ans[i-1][j-1];
                          
                     }
                     else{
                        ans1[i][j]=ans1[i-1][j]+ans1[i][j-1]-ans[i-1][j-1];
                     }
                 }
             }



            vector<vector<int>>diff(n,vector<int>(m,0));

            for(int i=0;i<n;i++){
                 for(int j=0;j<m;j++){
                     
                       diff[i][j]=ans[i][n-1]+ans[m-1][i]-ans1[i][n-1]-ans1[m-1][i];
                 }
            }


             return diff;


    }
};