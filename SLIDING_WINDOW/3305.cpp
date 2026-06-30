class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    long long atleastK(string &word, int k) {

        unordered_map<char, int> freq;
        long long ans = 0;

        int consonants = 0;
        int left = 0;

        for (int right = 0; right < word.size(); right++) {

            if (isVowel(word[right])) {
                freq[word[right]]++;
            } else {
                consonants++;
            }

            while (freq.size() == 5 && consonants >= k) {

                // Every extension of this window is also valid
                ans += word.size() - right;

                if (isVowel(word[left])) {
                    freq[word[left]]--;
                    if (freq[word[left]] == 0)
                        freq.erase(word[left]);
                } else {
                    consonants--;
                }

                left++;
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {

        return atleastK(word, k) - atleastK(word, k + 1);
    }
};