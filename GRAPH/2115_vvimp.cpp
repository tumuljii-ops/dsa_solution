class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        // Build graph
        for (int i = 0; i < recipes.size(); i++) {

            indegree[recipes[i]] = ingredients[i].size();

            for (string ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
        }

        queue<string> q;

        // Initial supplies
        for (string supply : supplies) {
            q.push(supply);
        }

        vector<string> ans;

        while (!q.empty()) {

            string item = q.front();
            q.pop();

            // Which recipes depend on this item
            for (string recipe : graph[item]) {

                indegree[recipe]--;

                // All ingredients available
                if (indegree[recipe] == 0) {

                    ans.push_back(recipe);

                    // recipe itself becomes supply
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};