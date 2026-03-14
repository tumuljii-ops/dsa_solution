class Solution {
public:
    bool isafe(int row,int j,vector<string>&store,int n){
           
         

           for(int k=0;k<n;k++){
            if(store[k][j]=='Q'){
                return false;
            }
           }

           int i=row;
           int u=j;

           while(i>=0 && u>=0){
                  if(store[i][u]=='Q'){
                    return false;
                  }
                  i=i-1;
                  u=u-1;
           }

            i=row;
            u=j;

           while(i>=0 && u<n){
               if(store[i][u]=='Q') return false;

               i=i-1;
               u=u+1;
           }

           return true;
    }

    void solve(int row,vector<vector<string>>&ans,vector<string>&store,int n){
             if(row==store.size()){
                  ans.push_back(store);
                  return ;
             }

            for(int j=0;j<n;j++){

                if(isafe(row,j,store,n)){
                    store[row][j]='Q';
                    solve(row+1,ans,store,n);
                    store[row][j]='.';

                }
            }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;

        vector<string>store(n,string(n,'.'));

        solve(0,ans,store,n);


        return ans;


    }
};