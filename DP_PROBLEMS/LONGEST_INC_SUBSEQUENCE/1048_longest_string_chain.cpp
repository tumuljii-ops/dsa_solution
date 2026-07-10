class Solution {
public:
    
    static bool compare(const string & a,const string & b){
          return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
         
          int n=words.size();

          sort(words.begin(),words.end(),compare);

          vector<int>dp(n,1);

          int ans=-1;

          for(int i=0;i<n;i++){
             for(int j=0;j<i;j++){
                 
                  if(isPrecedence(words[j],words[i])){
                      dp[i]=max(dp[i],dp[j]+1);
                  }
    
             }
             ans=max(ans,dp[i]);
          }

       return ans;


    }

    bool isPrecedence(string& small,string & large){
         
          if(small.length()+1!=large.length()){
              return false;
          }
          
          int i=0;
          int j=0;

          while(i<small.length() && j<large.size()){
             
                 if(small[i]==large[j]){
                      i++;
                      j++;
                 }
                 else{
                    j++;
                 }
          }

          return i==small.length();
    }
};