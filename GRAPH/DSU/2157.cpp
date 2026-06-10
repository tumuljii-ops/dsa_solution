class DSU {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void Union(int a, int b) {

        a = findParent(a);
        b = findParent(b);

        if (a == b) return;

        if (sz[a] < sz[b]) {
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];
    }

    int getSize(int x) {
        return sz[findParent(x)];
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {

        int n = words.size();

        DSU dsu(n);

        unordered_map<int, int> maskToIndex;

        for (int i = 0; i < n; i++) {

            int mask = 0;

            for (char ch : words[i]) {
                mask |= (1 << (ch - 'a'));
            }

            if (maskToIndex.count(mask)) {
                dsu.Union(i, maskToIndex[mask]);
            } else {
                maskToIndex[mask] = i;
            }
        }

        unordered_map<int, int> deletedMaskOwner;

        for (int i = 0; i < n; i++) {

            int mask = 0;

            for (char ch : words[i]) {
                mask |= (1 << (ch - 'a'));
            }

            // Add / Remove operation
            for (int b = 0; b < 26; b++) {

                int neighbor = mask ^ (1 << b);

                if (maskToIndex.count(neighbor)) {
                    dsu.Union(i, maskToIndex[neighbor]);
                }
            }

            // Replacement operation
            for (int b = 0; b < 26; b++) {

                if ((mask & (1 << b)) == 0) continue;

                int deletedMask = mask ^ (1 << b);

                if (deletedMaskOwner.count(deletedMask)) {
                    dsu.Union(i, deletedMaskOwner[deletedMask]);
                } else {
                    deletedMaskOwner[deletedMask] = i;
                }
            }
        }

        unordered_map<int, int> groupSize;

        int groups = 0;
        int largest = 0;

        for (int i = 0; i < n; i++) {

            int root = dsu.findParent(i);

            groupSize[root]++;
        }

        groups = groupSize.size();

        for (auto &it : groupSize) {
            largest = max(largest, it.second);
        }

        return {groups, largest};
    }
};