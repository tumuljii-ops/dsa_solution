class Solution {
public:
    int residuePrefixes(string s) {
        vector<int>freq(26,0);
        int ans=0;
        int n=s.length();
        int distinct=0;

        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==0){
                distinct++;
            }
            freq[s[i]-'a']++;
            int len=i+1;
            if(distinct==len%3){
                ans++;
            }
        }
        return ans;
    }
};