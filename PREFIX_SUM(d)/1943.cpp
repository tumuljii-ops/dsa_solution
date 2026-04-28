class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        map<long long, long long> mp;
        
        for (auto &seg : segments) {
            long long start = seg[0];
            long long end = seg[1];
            long long color = seg[2];

            mp[start] += color;
            mp[end] -= color;
        }

        vector<vector<long long>> ans;

        long long currColor = 0;
        long long prev = 0;

        for (auto it : mp) {
            long long pos = it.first;

            if (currColor > 0) {
                ans.push_back({prev, pos, currColor});
            }

            currColor += it.second;
            prev = pos;
        }

        return ans;
    }
};
