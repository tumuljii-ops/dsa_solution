class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {

        int mod = 1000;

        vector<int> dist(mod, INT_MAX);

        queue<pair<int,int>> q;

        q.push({0, start});

        dist[start] = 0;

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            int dis = top.first;
            int node = top.second;

            if(node == end) {
                return dis;
            }

            for(auto it : arr) {

                int val = (it * node) % mod;

                if(dis + 1 < dist[val]) {

                    dist[val] = dis + 1;

                    q.push({dist[val], val});
                }
            }
        }

        return -1;
    }
};