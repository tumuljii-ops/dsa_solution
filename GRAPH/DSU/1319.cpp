class Solution {
public:

    class Disjoint {
    public:
        vector<int> parent;
        vector<int> rank;
        int extraEdges = 0;

        Disjoint(int nodes) {
            parent.resize(nodes);
            rank.resize(nodes, 0);

            for (int i = 0; i < nodes; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        void UNION(int a, int b) {

            int parent_a = find(a);
            int parent_b = find(b);

            if (parent_a == parent_b) {
                extraEdges++;
                return;
            }

            if (rank[parent_a] < rank[parent_b]) {
                parent[parent_a] = parent_b;
            }
            else if (rank[parent_a] > rank[parent_b]) {
                parent[parent_b] = parent_a;
            }
            else {
                parent[parent_b] = parent_a;
                rank[parent_a]++;
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1) {
            return -1;
        }

        Disjoint ds(n);

        for (int i = 0; i < connections.size(); i++) {

            int x = connections[i][0];
            int y = connections[i][1];

            ds.UNION(x, y);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {

            if (ds.parent[i] == i) {
                components++;
            }
        }

        int needed = components - 1;

        if (ds.extraEdges >= needed) {
            return needed;
        }

        return -1;
    }
};