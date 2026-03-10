class Solution {
public:
    void call(vector<int> ans, vector<vector<int>>& anss, int ind, vector<int>& nums) {
        if (ind == nums.size()) {
            anss.push_back(ans);
            return;
        }

        ans.push_back(nums[ind]);
        call(ans, anss, ind + 1, nums);

        ans.pop_back();
        call(ans, anss, ind + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> anss;

        call(ans, anss, 0, nums);

        return anss;
    }
};