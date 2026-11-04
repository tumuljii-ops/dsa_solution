class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n + 1, false);
        vector<int> color(n + 1, 0);

        // for loop ko use karo disconnected component ko handle karne kai liye 

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                queue<pair<int, int>> q;
                q.push({i, 0});
                visited[i] = true;
                color[i] = 0;

                while (!q.empty()) {
                    auto top = q.front();
                    q.pop();

                    int u = top.first;
                    int v = top.second; 

                    for (auto it : adj[u]) {
                        if (!visited[it]) {
                            visited[it] = true;
                            int next_color = (v == 0) ? 1 : 0;
                            color[it] = next_color;
                            q.push({it, next_color});
                        } 
                        else {
                            if (color[it] == v) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};