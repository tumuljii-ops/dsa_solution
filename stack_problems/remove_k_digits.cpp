class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k) return "0";

        stack<char> st;

        for (char ch : num) {
            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);  
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top()); 
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        //------------total number of leading zeroes----------
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if (ans.size() == 0) return "0";

        return ans;
    }
};