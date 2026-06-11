class Solution {
public:
    int longestBeautifulSubstring(string word) {

        int n = word.size();
        int ans = 0;

        int len = 1;
        int distinct = 1;

        for (int i = 1; i < n; i++) {

            if (word[i] < word[i - 1]) {
                len = 1;
                distinct = 1;
            }
            else {
                len++;

                if (word[i] != word[i - 1]) {
                    distinct++;
                }
            }

            if (distinct == 5) {
                ans = max(ans, len);
            }
        }

        return ans;
    }
};