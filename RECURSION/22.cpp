class Solution {
public:
    void solve(int open,int close,int size,string curr,vector<string>&ans){
          
           if(size*2==curr.length()){
               ans.push_back(curr);
               return ;
           }

           if(open<size){
                solve(open+1,close,size,curr+"(",ans);
           }

           if(close<open){
              solve(open,close+1,size,curr+")",ans);
           }
    }
    vector<string> generateParenthesis(int n) {
           
           vector<string>ans;

           solve(0,0,n,"",ans);

           return ans;
    }
};