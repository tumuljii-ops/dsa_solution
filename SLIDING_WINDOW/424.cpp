class Solution {
public:
    int characterReplacement(string s, int k) {
           vector<int>freq(26,0);
           int n=s.length();

           int l=0;
           int r=0;
           int maxfreq=0;
           int result=0;


           while(r<n){
                freq[s[r]-'A']++;
                maxfreq=max(maxfreq,freq[s[r]-'A']);

                while((r-l+1)-maxfreq>k){
                      freq[s[l]-'A']--;
                      l++;
                }

                result=max(result,r-l+1);
                r++;
           }

           return result;
    }
};