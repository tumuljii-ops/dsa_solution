class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        int n = path.length();

        st.push('/');

        for (int i = 1; i < n; i++) {

            if (path[i] == '/' && st.top() == '/') continue;

            if (path[i] == '.') {

                if (st.top() != '/') {
                    st.push('.');
                    continue;
                }

                int dotCount = 0;

                while (i < n && path[i] == '.') {
                    dotCount++;
                    i++;
                }

                if (i == n || path[i] == '/') {

                    if (dotCount == 1) {
                        i--;
                        continue;
                    }
                    else if (dotCount == 2) {
                        if (st.size() > 1) {
                            st.pop();
                            while (st.size() > 1 && st.top() != '/') {
                                st.pop();
                            }
                        }
                        i--;
                        continue;
                    }
                    else {
                        while (dotCount--) st.push('.');
                    }
                }
                else {
                    while (dotCount--) st.push('.');
                }

                i--;
                continue;
            }

            if (path[i] == '/' && st.top() == '/') continue;
            st.push(path[i]);
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        if (ans.size() > 1 && ans.back() == '/') {
            ans.pop_back();
        }

        return ans;
    }
};