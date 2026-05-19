class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m){
            return false;
        }

        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        for(int i = 0; i < n; i++){
            hash1[s1[i] - 'a']++;
        }

        int left = 0;
        int right = 0;

        while(right < m){

            hash2[s2[right] - 'a']++;

            while((right - left + 1) > n){

                hash2[s2[left] - 'a']--;

                left++;
            }

            if(hash1 == hash2 && (right - left + 1) == n){
                return true;
            }

            right++;
        }

        return false;
    }
};