class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

private:
    bool isPredecessor(const string &small, const string &large) {
        if(large.size() != small.size() + 1) return false;

        int i = 0, j = 0;
        while(i < small.size() && j < large.size()){
            if(small[i] == large[j]){
                i++; j++;
            } else {
                j++; 
            }
        }
        return i == small.size();
    }
};
