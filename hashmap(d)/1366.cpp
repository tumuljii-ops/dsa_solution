class Solution {
public:
    string rankTeams(vector<string>& votes) {
           int m=votes[0].size();

           map<char,vector<int>>mpp;

           string ans1=votes[0];

           for(char ch:ans1){
               mpp[ch]=vector<int>(m,0);
           }

           for(string vote:votes){
                for(int i=0;i<m;i++){

                      mpp[vote[i]][i]++;
                }
           }

           sort(ans1.begin(),ans1.end(),[&](char a,char b){

                       if(mpp[a]!=mpp[b]){
                           return mpp[a]>mpp[b];
                       }

                   return a<b;
                    
               
           });

          return ans1;

               
    }
};