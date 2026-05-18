class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0, r = 0, maxLen = 0;
        int n = s.length();

        while (r < n) {
            if (seen.find(s[r]) == seen.end()) {
                seen.insert(s[r]);
                maxLen = max(maxLen, r - l + 1);
                r++;
            } else {
                seen.erase(s[l]);
                l++;
            }
        }

        return maxLen;
    }
};
