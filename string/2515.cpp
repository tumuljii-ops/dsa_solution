class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();
        int mini = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int dist = abs(i - startIndex);
                int circularDist = min(dist, n - dist);
                mini = min(mini, circularDist);
            }
        }

        if(mini == INT_MAX) return -1;
        return mini;
    }
};
