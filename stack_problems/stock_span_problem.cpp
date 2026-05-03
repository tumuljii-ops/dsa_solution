class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> ans(n, 0);
        stack<int> st;
        
        st.push(0);
        ans[0] = -1;   
        
        for (int i = 1; i < n; i++) {
            
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                ans[i] = -1;  
            } else {
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        vector<int> ret(n);
        
        for (int i = 0; i < n; i++) {
            ret[i] = i - ans[i];
        }
        
        return ret;
    }
};