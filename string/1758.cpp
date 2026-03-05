class Solution {
public:
    int minOperations(string s) {
         int mismatch0=0;
         int mismatch1=0;

         for(int i=0;i<s.length();i++){
             char c1;
             char c2;
             
             if(i%2==0) c1='0';
             else c1='1';

             if(i%2==0) c2='1';
             else c2='0';

             if(s[i]!=c1) mismatch0++;
             else if(s[i]!=c2) mismatch1++;
         }

         return min(mismatch0,mismatch1);
    }
};