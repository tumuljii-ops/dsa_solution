class Solution {
public:

    unordered_map<string, vector<pair<string,double>>> graph;

    double dfs(string curr,
               string target,
               unordered_set<string>& visited,
               double value){

        if(curr==target)
            return value;

        visited.insert(curr);

        for(auto &nbr : graph[curr]){

            string next = nbr.first;
            double weight = nbr.second;

            if(!visited.count(next)){

                double ans = dfs(next,
                                 target,
                                 visited,
                                 value*weight);

                if(ans!=-1.0)
                    return ans;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        for(int i=0;i<equations.size();i++){

            string u = equations[i][0];
            string v = equations[i][1];

            graph[u].push_back({v,values[i]});

            graph[v].push_back({u,1.0/values[i]});
        }

        vector<double> answer;

        for(auto &q : queries){

            string src=q[0];
            string dst=q[1];

            if(graph.find(src)==graph.end() ||
               graph.find(dst)==graph.end()){

                answer.push_back(-1.0);

                continue;
            }

            unordered_set<string> visited;

            answer.push_back(
                dfs(src,dst,visited,1.0)
            );
        }

        return answer;
    }
};