class Solution {
public:

    void buildGraph(TreeNode* root,
                    unordered_map<TreeNode*, vector<TreeNode*>>& adj)
    {
        if(!root) return;

        if(root->left)
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);

            buildGraph(root->left, adj);
        }

        if(root->right)
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);

            buildGraph(root->right, adj);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, vector<TreeNode*>> adj;

        buildGraph(root, adj);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while(!q.empty())
        {
            int sz = q.size();

            if(dist == k)
            {
                vector<int> ans;

                while(!q.empty())
                {
                    ans.push_back(q.front()->val);
                    q.pop();
                }

                return ans;
            }

            for(int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                for(auto nbr : adj[node])
                {
                    if(vis.find(nbr) == vis.end())
                    {
                        vis.insert(nbr);
                        q.push(nbr);
                    }
                }
            }

            dist++;
        }

        return {};
    }
};