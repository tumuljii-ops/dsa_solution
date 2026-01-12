class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // -------- LEFT: Previous Smaller Element (strictly smaller) --------
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = i + 1;
            } else {
                left[i] = i - st.top();
            }

            st.push(i);   // ✅ push index
        }

        while (!st.empty()) st.pop();

        // -------- RIGHT: Next Smaller or Equal Element --------
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - i;
            } else {
                right[i] = st.top() - i;
            }

            st.push(i);   // ✅ push index
        }

        // -------- CALCULATE ANSWER --------
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long contribution = (long long)arr[i] * left[i] * right[i];
            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};
