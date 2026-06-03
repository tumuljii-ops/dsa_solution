class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;   // {employee, time}

        q.push({headID, 0});

        int ans = 0;

        while(!q.empty()) {

            auto [node, time] = q.front();
            q.pop();

            ans = max(ans, time);

            for(auto child : adj[node]) {
                q.push({child, time + informTime[node]});
            }
        }

        return ans;
    }
};