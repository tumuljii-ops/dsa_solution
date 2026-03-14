class Solution {
public:
    bool valid(int row,int col,vector<string>&store,int n){
           
           for(int k=0;k<n;k++){
               if(store[row][k]=='Q') return false;
           }
           
           for(int k=0;k<n;k++){
               if(store[k][col]=='Q') return false;
           }


           int i=row;
           int j=col;

           while(i>=0 && j>=0){
               if(store[i][j]=='Q'){
                  return false;
               }
               i--;
               j--;
           }

           i=row;
           j=col;

           while(i>=0 && j<n){
                 if(store[i][j]=='Q'){
                    return false;
                 }

                 i--;
                 j++;
           }

           return true;

    }
    
    void perm(int row,vector<string>&store,vector<vector<string>>&ans,int n){
          
          if(row==n){
             ans.push_back(store);
             return;
          }

          for(int col=0;col<n;col++){

               if(valid(row,col,store,n)){
                    store[row][col]='Q';
                    perm(row+1,store,ans,n);
                    store[row][col]='.';
               }
          }

    }
    int totalNQueens(int n) {
        vector<string>store(n,string(n,'.'));
        vector<vector<string>>ans;

        perm(0,store,ans,n);


        return ans.size();
    }
};