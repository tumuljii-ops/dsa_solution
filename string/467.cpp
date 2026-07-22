class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Stores the maximum length of a valid block ending at each character ('a' through 'z')
        vector<int> max_len(26, 0); 

        for (int i = 0; i < n; ) {
            int j = i + 1;

            while (j < n && (s[j] - s[j-1] == 1 || s[j-1] - s[j] == 25)) {
                j++;
            }

            // We found a continuous valid block from index i to j-1
            int block_length = j - i;

            // Instead of generating substrings, we update the max length for each character in this block
            for (int k = 0; k < block_length; k++) {
                int char_idx = s[i + k] - 'a';
                
                // The valid sequence ending at this character has a length of (k + 1)
                max_len[char_idx] = max(max_len[char_idx], k + 1);
            }

            i = j; 
        }

        // Sum up the maximum lengths to get the total unique substrings
        int total_count = 0;
        for (int len : max_len) {
            total_count += len;
        }

        return total_count;
    }
};