class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = s.length();
        vector<int> total_shifts(n);

        int sum = 0;

        // build suffix sum (RIGHT FIX)
        for (int i = n - 1; i >= 0; i--) {
            sum = (sum + shifts[i]) % 26;
            total_shifts[i] = sum;
        }

        // apply shifts
        for (int i = 0; i < n; i++) {
            int shift = total_shifts[i];

            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
        }

        return s;
    }
};
