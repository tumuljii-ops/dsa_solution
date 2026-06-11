class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : connections) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        queue<int> q;
        vector<int> vis(n,0);

        q.push(0);
        vis[0] = 1;

        int ans = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto &[nbr,cost] : adj[node]) {

                if(vis[nbr]) continue;

                vis[nbr] = 1;
                ans += cost;

                q.push(nbr);
            }
        }

        return ans;
    }
};