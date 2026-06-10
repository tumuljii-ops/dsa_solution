class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);

        int i = s.length() - 2;

        // Find first decreasing digit from right
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        if (i < 0) return -1;

        // Find smallest greater digit on right
        int j = s.length() - 1;

        while (s[j] <= s[i]) {
            j--;
        }

        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());

        long long num = stoll(s);

        if (num > INT_MAX) return -1;

        return (int)num;
    }
};