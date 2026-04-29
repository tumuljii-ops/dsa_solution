class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        int mapS[256] = {0};  
        int mapT[256] = {0};  

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if (mapS[c1] != mapT[c2]) return false;
            mapS[c1] = i + 1;
            mapT[c2] = i + 1;
        }

        return true;
    }
};
