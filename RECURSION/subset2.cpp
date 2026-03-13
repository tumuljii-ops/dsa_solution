class Solution {
public:
    void call(vector<int>& nums, vector<vector<int>>& store, vector<int>& ans, int ind) {

        if (ind == nums.size()) {
            store.push_back(ans);
            return;
        }

        ans.push_back(nums[ind]);
        call(nums, store, ans, ind + 1);

        ans.pop_back();

        int index = ind + 1;

        while (index < nums.size() && nums[index] == nums[index - 1]) {
            index++;
        }

        call(nums, store, ans, index);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> store;
        vector<int> ans;

        call(nums, store, ans, 0);

        return store;
    }
};