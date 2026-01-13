class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();

        long long sumMin = getSumMin(arr, n);
        long long sumMax = getSumMax(arr, n);

        return sumMax - sumMin;
    }

private:
    long long getSumMin(vector<int>& arr, int n) {
        vector<int> left(n), right(n);
        stack<int> st;

        // -------- Previous Smaller --------
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = i + 1;
            } else {
                left[i] = i - st.top();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // -------- Next Smaller or Equal --------
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - i;
            } else {
                right[i] = st.top() - i;
            }

            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)arr[i] * left[i] * right[i];
        }

        return sum;
    }

    long long getSumMax(vector<int>& arr, int n) {
        vector<int> left(n), right(n);
        stack<int> st;

        // -------- Previous Greater --------
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = i + 1;
            } else {
                left[i] = i - st.top();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // -------- Next Greater or Equal --------
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - i;
            } else {
                right[i] = st.top() - i;
            }

            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)arr[i] * left[i] * right[i];
        }

        return sum;
    }
};
