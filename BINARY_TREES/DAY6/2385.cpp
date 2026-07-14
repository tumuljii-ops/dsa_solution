class Solution {
public:

    void buildParentMap(TreeNode* root,
                        unordered_map<TreeNode*,TreeNode*>& parent,
                        TreeNode*& startNode,
                        int start)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();

            if(current->val == start)
            {
                startNode = current;
            }

            if(current->left)
            {
                parent[current->left] = current;
                q.push(current->left);
            }

            if(current->right)
            {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*,TreeNode*> parent;

        TreeNode* startNode = NULL;

        buildParentMap(root,parent,startNode,start);

        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;

        q.push(startNode);
        visited[startNode] = true;

        int minutes = -1;

        while(!q.empty())
        {
            int size = q.size();

            minutes++;

            for(int i=0;i<size;i++)
            {
                TreeNode* current = q.front();
                q.pop();

                // left child
                if(current->left &&
                   !visited[current->left])
                {
                    visited[current->left] = true;
                    q.push(current->left);
                }

                // right child
                if(current->right &&
                   !visited[current->right])
                {
                    visited[current->right] = true;
                    q.push(current->right);
                }

                // parent
                if(parent.count(current) &&
                   !visited[parent[current]])
                {
                    visited[parent[current]] = true;
                    q.push(parent[current]);
                }
            }
        }

        return minutes;
    }
};