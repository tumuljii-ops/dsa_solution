class Solution {
public:
    void dfs(int num,int n,vector<int>&ans){
         
          if(num>n){
             return ;
          }

          ans.push_back(num);

          for(int digit=0;digit<=9;digit++){
             
               long long next=(long long)num*10 +digit;

               if(next>n){
                  break;
               }

               dfs(next,n,ans);
          }
    }
    vector<int> lexicalOrder(int n) {
          
          vector<int>ans;

          for(int i=1;i<=9;i++){
             
                 if(i>n){
                    break;
                 }

                 dfs(i,n,ans);
          }

          return ans;
    }
};