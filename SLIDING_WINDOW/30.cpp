class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> ans;

        int n = s.size();

        int wordLen = words[0].size();

        int totalWords = words.size();

        int windowLen = wordLen * totalWords;

        // Store required frequencies
        unordered_map<string,int> target;

        for(string word : words) {
            target[word]++;
        }

        // Try every possible offset
        for(int offset = 0; offset < wordLen; offset++) {

            unordered_map<string,int> window;

            int left = offset;

            int count = 0;

            // Move right pointer word-by-word
            for(int right = offset; right + wordLen <= n; right += wordLen) {

                string word = s.substr(right, wordLen);

                // Invalid word
                if(target.find(word) == target.end()) {

                    window.clear();

                    count = 0;

                    left = right + wordLen;

                    continue;
                }

                // Add current word
                window[word]++;

                count++;

                // Too many occurrences
                while(window[word] > target[word]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;

                    left += wordLen;

                    count--;
                }

                // Found valid window
                if(count == totalWords) {

                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};