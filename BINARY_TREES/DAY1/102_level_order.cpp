class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> store;

        if(root == nullptr) {
            return store;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            vector<int> ans;

            for(int i = 0; i < size; i++) {

                TreeNode* top = q.front();
                q.pop();

                ans.push_back(top->val);

                if(top->left != NULL) {
                    q.push(top->left);
                }

                if(top->right != NULL) {
                    q.push(top->right);
                }
            }

            store.push_back(ans);
        }

        return store;
    }
};