class Solution {
public:
    TreeNode* helper(unordered_set<int>& st, TreeNode* root, vector<TreeNode*>& ans) {
        if (!root) {
            return nullptr;
        }

        root->left = helper(st, root->left, ans);
        root->right = helper(st, root->right, ans);

        if (st.find(root->val) != st.end()) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            delete root; 
            return nullptr; 
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        if (!root) return ans;

        root = helper(st, root, ans);

        if (root) {
            ans.push_back(root);
        }

        return ans;
    }
};