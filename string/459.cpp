class Solution {
public:

    vector<int> buildLPS(string s) {
        int n = s.length();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> lps = buildLPS(s);
        int n = s.length();

        int len = lps[n - 1];

        if (len > 0 && n % (n - len) == 0) {
            return true;
        }

        return false;
    }
};
