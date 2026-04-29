class Solution {
public:

    string normalize(string s) {
        unordered_map<char, int> mpp;
        string res = "";
        int id = 0;

        for (int i = 0; i < s.length(); i++) {
            if (mpp.find(s[i]) == mpp.end()) {
                mpp[s[i]] = id;
                id++;
            }
            res += to_string(mpp[s[i]])+'#';
        }

        return res;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;

        string pat = normalize(pattern);

        for (int i = 0; i < words.size(); i++) {
            if (normalize(words[i]) == pat) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
