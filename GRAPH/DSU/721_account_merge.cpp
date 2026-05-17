class Solution {
public:

    class Disjoint {
    public:
        vector<int> parent;
        vector<int> rank;

        Disjoint(int n) {

            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) {
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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        Disjoint ds(n);
        
        unordered_map<string, int> mailToIndex;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mailToIndex.find(mail) == mailToIndex.end()) {

                    mailToIndex[mail] = i;
                }
                else {

                    ds.UNION(i, mailToIndex[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedMails;

        for (auto it : mailToIndex) {

            string mail = it.first;
            int node = it.second;

            int parent = ds.find(node);

            mergedMails[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        for (auto it : mergedMails) {

            int parent = it.first;

            vector<string> mails = it.second;

            sort(mails.begin(), mails.end());

            vector<string> temp;

            temp.push_back(accounts[parent][0]);

            for (string mail : mails) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};