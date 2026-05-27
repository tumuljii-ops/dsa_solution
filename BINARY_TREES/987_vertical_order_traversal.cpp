class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // col -> row -> sorted values
        map<int, map<int, multiset<int>>> nodes;

        // queue: node, {row, col}
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()) {

            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;

            int row = front.second.first;
            int col = front.second.second;

            // Store node
            nodes[col][row].insert(node->val);

            // Left child
            if(node->left) {

                q.push({
                    node->left,
                    {row + 1, col - 1}
                });
            }

            // Right child
            if(node->right) {

                q.push({
                    node->right,
                    {row + 1, col + 1}
                });
            }
        }

        vector<vector<int>> ans;

        // Traverse columns
        for(auto colPair : nodes) {

            vector<int> col;

            // Traverse rows
            for(auto rowPair : colPair.second) {

                // Sorted values
                for(auto val : rowPair.second) {

                    col.push_back(val);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};