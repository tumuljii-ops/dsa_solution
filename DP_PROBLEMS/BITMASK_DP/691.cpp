class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {

        int n = target.size();

        int fullMask = (1 << n) - 1;

        vector<int> dp(1 << n, 1e9);

        dp[0] = 0;

        for(int mask = 0; mask <= fullMask; mask++) {

            if(dp[mask] == 1e9)
                continue;

            for(string &sticker : stickers) {

                int newMask = mask;

                vector<int> freq(26,0);

                for(char ch : sticker)
                    freq[ch-'a']++;

                // Apply sticker
                for(int i=0;i<n;i++) {

                    if(newMask & (1<<i))
                        continue;

                    char need = target[i];

                    if(freq[need-'a'] > 0) {

                        freq[need-'a']--;

                        newMask |= (1<<i);
                    }
                }

                dp[newMask] =
                    min(dp[newMask],
                        dp[mask] + 1);
            }
        }

        return dp[fullMask] == 1e9
               ? -1
               : dp[fullMask];
    }
};