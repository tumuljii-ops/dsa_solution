class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int n1 = ransomNote.length();
        int n2 = magazine.length();

        if (n1 > n2) return false;

        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        // Count frequency of ransomNote
        for (int i = 0; i < n1; i++) {
            hash1[ransomNote[i] - 'a']++;
        }

        // Count frequency of magazine
        for (int j = 0; j < n2; j++) {
            hash2[magazine[j] - 'a']++;
        }

        // Compare frequencies
        for (int i = 0; i < 26; i++) {
            if (hash1[i] > hash2[i]) {
                return false;
            }
        }

        return true;
    }
};
