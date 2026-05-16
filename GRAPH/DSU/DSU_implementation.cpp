#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

public:

    vector<int> parent;
    vector<int> size;

    // Constructor
    DisjointSet(int n) {

        // Resize arrays
        parent.resize(n + 1);

        // Initially size of every component is 1
        size.resize(n + 1, 1);

        // Initially every node
        // is parent of itself
        for (int i = 0; i <= n; i++) {

            parent[i] = i;
        }
    }

    // Find ultimate parent of node
    int findParent(int node) {

        // If node itself is parent
        // then it is ultimate parent
        if (node == parent[node]) {

            return node;
        }

        // PATH COMPRESSION
        // Directly connect node
        // to ultimate parent
        return parent[node]
               = findParent(parent[node]);
    }

    // Union by Size
    void unionBySize(int u, int v) {

        // Find ultimate parents
        int pu = findParent(u);
        int pv = findParent(v);

        // Already in same component
        if (pu == pv) {

            return;
        }

        // Smaller component joins bigger component

        if (size[pu] < size[pv]) {

            parent[pu] = pv;

            size[pv] += size[pu];
        }
        else {

            parent[pv] = pu;

            size[pu] += size[pv];
        }
    }
};

int main() {

    // Create DSU for 7 nodes
    DisjointSet ds(7);

    // Connect nodes
    ds.unionBySize(1, 2);

    ds.unionBySize(2, 3);

    ds.unionBySize(4, 5);

    ds.unionBySize(6, 7);

    ds.unionBySize(5, 6);

    // Check if nodes belong to same component

    if (ds.findParent(3) == ds.findParent(7)) {

        cout << "Same Component\n";
    }
    else {

        cout << "Different Component\n";
    }

    // Now connect both components
    ds.unionBySize(3, 7);

    // Check again

    if (ds.findParent(3) == ds.findParent(7)) {

        cout << "Same Component\n";
    }
    else {

        cout << "Different Component\n";
    }

    return 0;
}