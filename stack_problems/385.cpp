class Solution {
public:
    NestedInteger deserialize(string s) {
        // 1. Base case: If string is just a single number without brackets
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        // 2. Stack to keep track of nested list levels
        stack<NestedInteger> st;
        int num = 0;
        bool negative = false;
        bool isNum = false; // Tracks if we are currently parsing digits

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '[') {
                // Start a new list level on top of the stack
                st.push(NestedInteger());
            } 
            else if (c == '-') {
                negative = true;
            } 
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                isNum = true;
            } 
            else if (c == ',' || c == ']') {
                // Add completed number to the current active list
                if (isNum) {
                    if (negative) num = -num;
                    st.top().add(NestedInteger(num));
                    num = 0;
                    negative = false;
                    isNum = false;
                }
                
                // If closing a bracket, pop current level and attach it to parent level
                if (c == ']' && st.size() > 1) {
                    NestedInteger completedList = st.top();
                    st.pop();
                    st.top().add(completedList);
                }
            }
        }

        return st.top();
    }
};