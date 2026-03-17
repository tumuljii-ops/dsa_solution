class Solution {
public:
    void solve(vector<int>& candidates, int target, int ind,
               vector<int>& path, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (ind == candidates.size() || target < 0) {
            return;
        }

        // take current
        path.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], ind, path, ans);
        path.pop_back();

        // skip current
        solve(candidates, target, ind + 1, path, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(candidates, target, 0, path, ans);
        return ans;
    }
};