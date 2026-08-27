#include <string>
#include <stack>

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int deletions = 0;

        // Traverse from right to left (back to front)
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s[i];

            // If stack has 'a' (from the right) and current character is 'b' (on the left)
            if (!st.empty() && st.top() == 'a' && ch == 'b') {
                st.pop();        // Destroy the invalid pair
                deletions++;     // Count 1 deletion
            } else {
                st.push(ch);     // Keep pushing characters (especially 'a's)
            }
        }

        return deletions;
    }
};