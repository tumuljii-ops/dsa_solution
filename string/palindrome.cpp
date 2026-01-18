

class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for (char c : s) {
            if (isupper(c)) {
                ans += tolower(c);
            } else if (islower(c) || isdigit(c)) {
                ans += c;
            }
           
        }

        int n = ans.length();
        for (int i = 0; i < n / 2; i++) {
            if (ans[i] != ans[n - i - 1]) {
                return false; 
            }
        }
        return true;
    }
};