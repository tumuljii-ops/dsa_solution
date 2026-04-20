class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& comp, vector<bool>& vis) {
        vis[node] = true;
        comp.push_back(node);

        for(int nei : adj[node]) {
            if(!vis[nei]) {
                dfs(nei, adj, comp, vis);
            }
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        // 🔧 build graph from swaps
        vector<vector<int>> adj(n);
        for(auto &e : allowedSwaps) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int hamm_dist = 0;

        // 🔧 process each connected component
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vector<int> comp;
                dfs(i, adj, comp, vis);

                // count frequencies
                unordered_map<int,int> freq;

                for(int idx : comp) {
                    freq[source[idx]]++;
                }

                // match with target
                for(int idx : comp) {
                    if(freq[target[idx]] > 0) {
                        freq[target[idx]]--;
                    } else {
                        hamm_dist++;
                    }
                }
            }
        }

        return hamm_dist;
    }
};