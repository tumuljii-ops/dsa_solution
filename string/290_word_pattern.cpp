class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, string> mpp;
        unordered_map<string, char> rev; // reverse map

        int i = 0, j = 0;
        int n = pattern.length();
        int n1 = s.length();

        while (i < n && j < n1) {

            string ans = "";

            // extract word
            while (j < n1 && s[j] != ' ') {
                ans += s[j];
                j++;
            }

            // skip space
            j++;

            // check mapping
            if (mpp.find(pattern[i]) != mpp.end()) {
                if (mpp[pattern[i]] != ans) return false;
            } else {
                mpp[pattern[i]] = ans;
            }

            // check reverse mapping
            if (rev.find(ans) != rev.end()) {
                if (rev[ans] != pattern[i]) return false;
            } else {
                rev[ans] = pattern[i];
            }

            i++;
        }

        // extra check: both should finish together
        if (i != n || j < n1) return false;

        return true;
    }
};
