class Solution {
public:
    void solve(int ind,string ans,vector<string>&mp,vector<string>&store,string digits){
         
         if(ind==digits.size()){
            store.push_back(ans);
            return ;
         }

         string compare=mp[digits[ind]-'0'];

         for(int i=0;i<compare.size();i++){
               ans.push_back(compare[i]);
               solve(ind+1,ans,mp,store,digits);
               ans.pop_back();
         }
    }
    vector<string> letterCombinations(string digits) {
             vector<string>store;

             if(digits.size()==0) return store;

             vector<string>mp(10);

             mp[2]="abc";
             mp[3]="def";
             mp[4]="ghi";
             mp[5]="jkl";
             mp[6]="mno";
             mp[7]="pqrs";
             mp[8]="tuv";
             mp[9]="wxyz";

             string ans="";

             solve(0,ans,mp,store,digits);

             return store;
    }
};