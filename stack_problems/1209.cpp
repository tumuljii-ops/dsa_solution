class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack stores pair: {character, consecutive_count}
        stack<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                // Increment count for existing top character
                st.top().second++;
            } else {
                // Push new character with an initial count of 1
                st.push({c, 1});
            }

            // If we reach k consecutive duplicate characters, remove the group
            if (st.top().second == k) {
                st.pop();
            }
        }

        // Reconstruct the remaining string
        string ans = "";
        while (!st.empty()) {
            ans.append(st.top().second, st.top().first);
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};