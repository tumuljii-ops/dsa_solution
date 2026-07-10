class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> adj(v);
        vector<int> indegree(v, 0);

        for (auto &edge : prerequisites) {
            int u = edge[0];   
            int vv = edge[1];  

            adj[vv].push_back(u); 
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();   
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return (count == numCourses);
    }
};