class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        stack<TreeNode*> st;

        TreeNode* curr = root;

        TreeNode* lastVisited = NULL;

        while(curr || !st.empty()) {

            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* node = st.top();

            if(node->right && lastVisited != node->right) {

                curr = node->right;
            }
            else {

                ans.push_back(node->val);

                lastVisited = node;

                st.pop();
            }
        }

        return ans;
    }
};