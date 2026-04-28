class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        
        int n = s.size();

        vector<long long> nextPrefix(27, 0), prevPrefix(27, 0);

        for (int i = 0; i < 26; i++) {
            nextPrefix[i + 1] = nextPrefix[i] + nextCost[i];
            prevPrefix[i + 1] = prevPrefix[i] + previousCost[i];
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            int y = t[i] - 'a';

            long long forward;
            if (y >= x) {
                forward = nextPrefix[y] - nextPrefix[x];
            } else {
                forward = (nextPrefix[26] - nextPrefix[x]) + nextPrefix[y];
            }

            long long backward;
            if (x >= y) {
                backward = prevPrefix[x + 1] - prevPrefix[y + 1];
            } else {
                backward = prevPrefix[x + 1] + (prevPrefix[26] - prevPrefix[y + 1]);
            }

            ans += min(forward, backward);
        }

        return ans;
    }
};
