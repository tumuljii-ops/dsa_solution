class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
       int n1=s.length();
       int n2=t.length();
        if(n1!=n2)return false;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                return false ;
                break;
            }
            
        }
        return true;
    }
};