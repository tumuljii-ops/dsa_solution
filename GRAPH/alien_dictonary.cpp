class Solution {
public:
    string findOrder(vector<string> &words) {
        
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        
        int n = words.size();

      
        for(auto word : words){
            for(auto ch : word){
                present[ch - 'a'] = true;
            }
        }

    
        for(int i = 1; i < n; i++){
            string s1 = words[i - 1];
            string s2 = words[i];

            int p = 0, q = 0;

            while(p < s1.length() && q < s2.length()){
                if(s1[p] != s2[q]){
                    adj[s1[p] - 'a'].push_back(s2[q] - 'a');
                    indegree[s2[q] - 'a']++;
                    break;
                }
                p++;
                q++;
            }

            if(p == s2.length() && s1.length() > s2.length()){
                return "";
            }
        }

        queue<int> q;
        for(int i = 0; i < 26; i++){
            if(present[i] && indegree[i] == 0){
                q.push(i);
            }
        }

        string result = "";

        while(!q.empty()){
            int node = q.front();
            q.pop();

            result += (node + 'a');

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

 
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(present[i]) count++;
        }

        if(result.size() != count){
            return "";
        }

        return result;
    }
};

