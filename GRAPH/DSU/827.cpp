class Solution {
public:

    class DSU {

    public:

        vector<int> parent;
        vector<int> size;

        DSU(int n) {

            // total nodes = n

            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {

            // node itself is parent

            if (parent[x] == x) {
                return x;
            }

            // path compression

            return parent[x] = find(parent[x]);
        }

        void Union(int a, int b) {

            int parent_a = find(a);
            int parent_b = find(b);

            // already connected

            if (parent_a == parent_b) {
                return;
            }

            // attach smaller component to bigger component

            if (size[parent_a] < size[parent_b]) {

                parent[parent_a] = parent_b;

                // increase total component size

                size[parent_b] += size[parent_a];
            }
            else {

                parent[parent_b] = parent_a;

                // increase total component size

                size[parent_a] += size[parent_b];
            }
        }
    };

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        // DSU for all n*n cells

        DSU ds(n * n);

        // -------------------------------------------------
        // STEP 1:
        // connect all adjacent 1s
        // -------------------------------------------------

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                // skip water cell

                if (grid[i][j] == 0) {
                    continue;
                }

                // convert 2D -> 1D

                int node = i * n + j;

                // ================= TOP =================

                if (i - 1 >= 0 && grid[i - 1][j] == 1) {

                    int adjNode = (i - 1) * n + j;

                    ds.Union(node, adjNode);
                }

                // ================= RIGHT =================

                if (j + 1 < n && grid[i][j + 1] == 1) {

                    int adjNode = i * n + (j + 1);

                    ds.Union(node, adjNode);
                }

                // ================= DOWN =================

                if (i + 1 < n && grid[i + 1][j] == 1) {

                    int adjNode = (i + 1) * n + j;

                    ds.Union(node, adjNode);
                }

                // ================= LEFT =================

                if (j - 1 >= 0 && grid[i][j - 1] == 1) {

                    int adjNode = i * n + (j - 1);

                    ds.Union(node, adjNode);
                }
            }
        }

        int maxi = 0;

        // -------------------------------------------------
        // STEP 2:
        // try converting each 0 into 1
        // -------------------------------------------------

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                // only process 0 cells

                if (grid[i][j] == 1) {
                    continue;
                }

                // store unique neighboring islands

                unordered_set<int> st;

                // ================= TOP =================

                if (i - 1 >= 0 && grid[i - 1][j] == 1) {

                    int parent =
                    ds.find((i - 1) * n + j);

                    st.insert(parent);
                }

                // ================= RIGHT =================

                if (j + 1 < n && grid[i][j + 1] == 1) {

                    int parent =
                    ds.find(i * n + (j + 1));

                    st.insert(parent);
                }

                // ================= DOWN =================

                if (i + 1 < n && grid[i + 1][j] == 1) {

                    int parent =
                    ds.find((i + 1) * n + j);

                    st.insert(parent);
                }

                // ================= LEFT =================

                if (j - 1 >= 0 && grid[i][j - 1] == 1) {

                    int parent =
                    ds.find(i * n + (j - 1));

                    st.insert(parent);
                }

                // flipped cell contributes 1

                int totalSize = 1;

                // add sizes of all unique islands

                for (auto parent : st) {

                    totalSize += ds.size[parent];
                }

                maxi = max(maxi, totalSize);
            }
        }

        // -------------------------------------------------
        // STEP 3:
        // edge case:
        // if grid already full of 1s
        // -------------------------------------------------

        for (int i = 0; i < n * n; i++) {

            int parent = ds.find(i);

            maxi = max(maxi, ds.size[parent]);
        }

        return maxi;
    }
};