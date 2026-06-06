class Solution {
public:

    bool possible(int source, int col,
                  vector<vector<int>>& adj,
                  vector<int>& color) {

        for (auto it : adj[source]) {

            if (color[it] == col) {
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<int>>& adj,
               vector<int>& color,
               int src,
               int m) {

        if (src == adj.size()) {
            return true;
        }

        for (int clr = 1; clr <= m; clr++) {

            if (possible(src, clr, adj, color)) {

                color[src] = clr;

                if (solve(adj, color, src + 1, m)) {
                    return true;
                }

                color[src] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int v,
                       vector<vector<int>>& edges,
                       int m) {

        vector<vector<int>> adj(v);

        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int vv = edges[i][1];

            adj[u].push_back(vv);
            adj[vv].push_back(u);
        }

        vector<int> color(v, 0);

        return solve(adj, color, 0, m);
    }
};