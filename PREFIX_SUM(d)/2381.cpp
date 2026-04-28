class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
                 
        int n = s.length();
        vector<int> prefix(n, 0); 

        int len = shifts.size();     

        for (int i = 0; i < len; i++) {
                       
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];

            int val = (dir == 1) ? 1 : -1;
            prefix[start] += val;

            if (end + 1 < n) {
                prefix[end + 1] -= val;
            }
        } 

        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int shift = prefix[i] % 26;

            if (shift < 0) shift += 26;

            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
        }

        return s;
    } 
};
