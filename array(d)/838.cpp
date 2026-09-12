class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n = s.length();
        int left = 0; 

        for (int right = 1; right < n; right++) {
            if (s[right] == '.') continue; 

            int count = right - left - 1; 

            if (s[left] == s[right]) {
                // Rule 1 & 2: Same forces (R...R or L...L) -> fill with that force
                for (int i = 1; i <= count; i++) {
                    s[left + i] = s[left];
                }
            } 
            else if (s[left] == 'R' && s[right] == 'L') {
                // Rule 4: Opposing forces towards each other (R...L) -> meet in middle
                for (int i = 1; i <= count / 2; i++) {
                    s[left + i] = 'R';
                    s[right - i] = 'L';
                }
            }
            // Rule 3: (L...R) -> Do nothing! Dots remain '.'

            left = right; // Move left pointer to current right force
        }

        // Step 2: Remove boundary padding
        return s.substr(1, dominoes.length());
    }
};