class Solution {
public:

    vector<string> ans;

    void dfs(TreeNode* root, string path) {

        if(root == NULL) {
            return;
        }

        // add current node
        path += to_string(root->val);

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // continue path
        path += "->";

        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        dfs(root, "");

        return ans;
    }
};