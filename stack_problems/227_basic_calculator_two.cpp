class Solution {
public:

    int calculate(string s) {

        stack<int> st;

        int num = 0;

        char op = '+';

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];

            // Build number
            if(isdigit(ch)) {

                num = num * 10 + (ch - '0');
            }

            // If operator OR last character
            if((!isdigit(ch) && ch != ' ') || i == s.length() - 1) {

                if(op == '+') {

                    st.push(num);
                }

                else if(op == '-') {

                    st.push(-num);
                }

                else if(op == '*') {

                    int top = st.top();
                    st.pop();

                    st.push(top * num);
                }

                else if(op == '/') {

                    int top = st.top();
                    st.pop();

                    st.push(top / num);
                }

                // Update operator
                op = ch;

                // Reset number
                num = 0;
            }
        }

        int ans = 0;

        while(!st.empty()) {

            ans += st.top();
            st.pop();
        }

        return ans;
    }
};