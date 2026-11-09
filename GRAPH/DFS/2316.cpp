class Solution {
public:

    int dfs(vector<bool>& visited, int src, vector<vector<int>>& adj) {
        int count = 1;
        visited[src] = true;

        for (int i = 0; i < adj[src].size(); i++) {
            int it = adj[src][i];
            
            if (visited[it] == false) {
                count = count + dfs(visited, it, adj);
            }
        }

        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        int x = edges.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < x; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<long long> ans;

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                long long num = dfs(visited, i, adj);
                ans.push_back(num);
            }
        }

        if (ans.size() == 1) {
            return 0;
        }

        long long total_pairs = 0;
        long long sum_so_far = 0;

        for (int i = 0; i < ans.size(); i++) {
            total_pairs = total_pairs + (ans[i] * sum_so_far);
            sum_so_far = sum_so_far + ans[i];
        }

        return total_pairs;
    }
};