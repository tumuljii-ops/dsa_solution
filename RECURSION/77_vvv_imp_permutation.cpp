class Solution {
public:

    void total(int start,
               int n,
               int k,
               vector<int>& curr,
               vector<vector<int>>& ans)
    {
        if(curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        for(int j = start; j <= n; j++)
        {
            curr.push_back(j);

            total(j + 1, n, k, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        total(1, n, k, curr, ans);

        return ans;
    }
};