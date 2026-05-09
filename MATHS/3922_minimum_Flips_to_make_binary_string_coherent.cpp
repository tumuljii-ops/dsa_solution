class Solution {
public:
    int minFlips(string s) {
           
           int n=s.length();

           if(n<3) return 0;

           int count0=0;

           for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    count0++;
                }
           }

           int count1=n-count0;

           int res1=min(count0,count1);

           int res2=max(count1-1,0);

           int res3=count1-(s[0]-'0')-(s[n-1]-'0');

           return min({res1,res2,res3});
    }
};