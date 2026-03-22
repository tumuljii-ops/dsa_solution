#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int node, int clr, vector<vector<int>>& adj, vector<int>& color) {
        for (int nbr : adj[node]) {
            if (color[nbr] == clr) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int v, vector<vector<int>>& adj, int m, vector<int>& color) {
        if (node == v) {
            return true;
        }

        for (int clr = 1; clr <= m; clr++) {
            if (isSafe(node, clr, adj, color)) {
                color[node] = clr;

                if (solve(node + 1, v, adj, m, color)) {
                    return true;
                }

                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>>& edges, int m) {
        vector<vector<int>> adj(v);

        for (auto it : edges) {
            int u = it[0];
            int w = it[1];

            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        vector<int> color(v, 0);

        return solve(0, v, adj, m, color);
    }
};

int main() {
    int v, e, m;
    cin >> v >> e >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        edges.push_back({u, w});
    }

    Solution obj;

    if (obj.graphColoring(v, edges, m)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}