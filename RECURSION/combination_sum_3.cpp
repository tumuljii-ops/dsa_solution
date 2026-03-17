class Solution {
public:
    void combi(vector<int>& ans, vector<vector<int>>& store, int sum, int target,
               int k, int ind, int count, vector<int>& candidate) {
        
        if (sum == target && count == k) {
            store.push_back(ans);
            return;
        }

        if (sum > target || count > k || ind >= candidate.size()) return;

        // take
        if (sum + candidate[ind] <= target && count < k) {
            ans.push_back(candidate[ind]);
            combi(ans, store, sum + candidate[ind], target, k, ind + 1, count + 1, candidate);
            ans.pop_back();
        }

        // not take
        combi(ans, store, sum, target, k, ind + 1, count, candidate);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidate(9);

        for (int i = 0; i < 9; i++) {
            candidate[i] = i + 1;
        }

        vector<int> ans;
        vector<vector<int>> store;

        combi(ans, store, 0, n, k, 0, 0, candidate);

        return store;
    }
};