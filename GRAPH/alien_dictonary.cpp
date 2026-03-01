   vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        for (auto &w : words)
            for (char c : w)
                present[c - 'a'] = 1;

        // Build graph + prefix invalid check
        for (int i = 0; i < (int)words.size() - 1; i++) {
            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());
            int j = 0;

            while (j < len && a[j] == b[j]) j++;

            // if b is prefix of a => invalid
            if (j == len && a.size() > b.size()) return "";

            // first mismatch gives edge
            if (j < len) {
                int u = a[j] - 'a';
                int v = b[j] - 'a';
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        // Topo sort (Kahn)
        queue<int> q;
        int total = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                total++;
                if (indegree[i] == 0) q.push(i);
            }
        }

        string ans = "";
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(char('a' + node));

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        // Cycle check
        if ((int)ans.size() != total) return "";
        return ans;