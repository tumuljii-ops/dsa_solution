class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        int length = 0;

        for (const string& word : words) {
           
            string rev = string(word.rbegin(), word.rend());

            if (mpp[rev] > 0) {
                length += 4;
                mpp[rev]--;
            } else {
                mpp[word]++;
            }
        }

        for (auto& [word, count] : mpp) {
            if (word[0] == word[1] && count > 0) {
                length += 2;
                break; 
            }
        }

        return length;
    }
};