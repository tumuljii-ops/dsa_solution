class DSU {

private:
    vector<int> parent;
    vector<int> rank;

public:

    DSU(int n) {

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int x) {

        if (parent[x] == x)
            return x;

        return parent[x] = findparent(parent[x]);
    }

    void Union(int a, int b) {

        int a_parent = findparent(a);
        int b_parent = findparent(b);

       

        if (rank[a_parent] < rank[b_parent]) {
            parent[a_parent] = b_parent;
        }
        else if (rank[a_parent] > rank[b_parent]) {
            parent[b_parent] = a_parent;
        }
        else {
            parent[a_parent] = b_parent;
            rank[b_parent]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        DSU dsu(26);

        for (string &eqs : equations) {

            if (eqs[1] == '=') {

                int u = eqs[0] - 'a';
                int v = eqs[3] - 'a';

                dsu.Union(u, v);
            }
        }

        for (string &eqs : equations) {

            if (eqs[1] == '!') {

                int u = eqs[0] - 'a';
                int v = eqs[3] - 'a';

                if (dsu.findparent(u) == dsu.findparent(v))
                    return false;
            }
        }

        return true;
    }
};