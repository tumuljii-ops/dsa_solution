class Solution {
public:
    string maximumXor(string s, string t) {

        int n = t.length();
        int total_one = 0;
        int total_zero = 0;

        for (int i = 0; i < n; i++) {
            if (t[i] == '0') total_zero++;
            else total_one++;
        }

        string ans;
        ans.reserve(n);   // IMPORTANT: prevents O(n^2)

        int i = 0;
        while (total_one > 0 && total_zero > 0 && i < n) {
            if (s[i] == '1') {
                ans.push_back('0');
                total_zero--;
            } else {
                ans.push_back('1');
                total_one--;
            }
            i++;
        }

        // Fill remaining positions until length becomes n
        while ((int)ans.size() < n && total_one > 0) {
            ans.push_back('1');
            total_one--;
        }

        while ((int)ans.size() < n && total_zero > 0) {
            ans.push_back('0');
            total_zero--;
        }

        string answer;
        answer.reserve(n); // IMPORTANT

        for (int i = 0; i < n; i++) {
            // XOR directly (your if-else compressed)
            if (ans[i] == s[i]) answer.push_back('0');
            else answer.push_back('1');
        }

        return answer;
    }
};