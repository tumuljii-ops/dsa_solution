class DSU {
private:
    vector<int> parent;

public:

    DSU(int n) {
        parent.resize(n);

        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }

    int findparent(int x) {

        if(parent[x]==x)
            return x;

        return parent[x]=findparent(parent[x]);
    }

    void Union(int a,int b) {

        int pa=findparent(a);
        int pb=findparent(b);

        if(pa==pb) return;

        // smaller character becomes leader
        if(pa < pb)
            parent[pb]=pa;
        else
            parent[pa]=pb;
    }
};

class Solution {
public:
    string smallestEquivalentString(
        string s1,
        string s2,
        string baseStr) {

        DSU dsu(26);

        for(int i=0;i<s1.size();i++) {

            int x=s1[i]-'a';
            int y=s2[i]-'a';

            dsu.Union(x,y);
        }

        string ans="";

        for(char ch : baseStr) {

            int root = dsu.findparent(ch-'a');

            ans.push_back(root+'a');
        }

        return ans;
    }
};