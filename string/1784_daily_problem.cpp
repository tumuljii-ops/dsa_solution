class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ans=true;

        for(int i=1;i<s.length();i++){
            if(s[i]=='1' && s[i-1]=='0'){
                ans=false;
                break;
            }
        } 

        return ans;  
    }
};