class Solution {
public:
    int countSubstrings(string s) {
        string t = "^";
        
        for(int i = 0; i < s.size(); i++){
            t = t + "#" + s[i];
        }
        
        t = t + "#$";

        int n = t.size();
        vector<int> P(n, 0);

        int C = 0;
        int R = 0;

        for(int i = 1; i < n - 1; i++){
            int mirror = 2 * C - i;

            if(i < R){
                if(R - i < P[mirror]){
                    P[i] = R - i;
                }
                else{
                    P[i] = P[mirror];
                }
            }

            // Expand
            while(t[i + 1 + P[i]] == t[i - 1 - P[i]]){
                P[i] = P[i] + 1;
            }

            // Update center and right
            if(i + P[i] > R){
                C = i;
                R = i + P[i];
            }
        }

        // Count palindromes
        int count = 0;
        for(int i = 1; i < n - 1; i++){
            count = count + (P[i] + 1) / 2;
        }

        return count;
    }
};
