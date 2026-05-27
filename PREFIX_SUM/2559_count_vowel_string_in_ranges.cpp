class Solution {
public:
    bool isvowel(char s) {
        s = tolower(s);
        return (s=='a'||s=='e'||s=='i'||s=='o'||s=='u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = words.size();
        vector<int> prefixsum(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            int num = words[i].length();
            if (isvowel(words[i][0]) && isvowel(words[i][num - 1])) {
                count++;
            }
            prefixsum[i] = count;
        }

        vector<int> ans;
        for (int i = 0; i < (int)queries.size(); i++) {
            int j = queries[i][0];
            int k = queries[i][1];

            if (j == 0) ans.push_back(prefixsum[k]);
            else ans.push_back(prefixsum[k] - prefixsum[j - 1]);
        }

        return ans;
    }
};