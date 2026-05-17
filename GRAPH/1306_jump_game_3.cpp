class Solution {
public:

    bool dfs(int ind, vector<int>& arr, vector<int>& vis) {

        if(ind < 0 || ind >= arr.size() || vis[ind]) {
            return false;
        }

        if(arr[ind] == 0) {
            return true;
        }

        vis[ind] = 1;

        int forward = ind + arr[ind];
        int backward = ind - arr[ind];

        return dfs(forward, arr, vis) || dfs(backward, arr, vis);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<int> vis(arr.size(), 0);

        return dfs(start, arr, vis);
    }
};