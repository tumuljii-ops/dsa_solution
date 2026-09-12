class Solution {
public:
    int longestBalanced(string s) {
          
            int n=s.length();
            int max_len=1;

            for(int i=0;i<n;i++){
                 
                 vector<int>freq(26,0);
                 unordered_set<char>seen;

                 for(int j=i;j<n;j++){
                     
                        freq[s[j]-'a']++;

                        seen.insert(s[j]);
                        bool ans=true;

                        int u=freq[s[j]-'a'];

                        for(int k=0;k<26;k++){
                             
                              if(seen.find('a'+k)!=seen.end()){
                                 
                                      if(freq[k]!=u){
                                           ans=false;
                                           break;
                                      }
                              }
                        }

                        if(ans){
                             max_len=max(max_len,j-i+1);
                        }
                        else{
                            ans=true;
                        }
                 }
            }

            return max_len;
    }
};