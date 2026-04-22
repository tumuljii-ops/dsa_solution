class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) {
            return false;
        }

        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        for (int i = 0; i < n; i++) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }

        if (hash1 == hash2) {
            return true;
        }

        for (int i = n; i < m; i++) {
            hash2[s2[i] - 'a']++;
            hash2[s2[i - n] - 'a']--;

            if (hash1 == hash2) {
                return true;
            }
        }

        return false;
    }
};