class Solution {
public:

    int ans = 0;

    void dfs(TreeNode* root, bool left, int len){

        if(root == NULL)
            return;

        ans = max(ans, len);

        if(left){

            // Continue ZigZag
            dfs(root->right, false, len + 1);

            // Restart
            dfs(root->left, true, 1);
        }
        else{

            // Continue ZigZag
            dfs(root->left, true, len + 1);

            // Restart
            dfs(root->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {

        dfs(root->left, true, 1);

        dfs(root->right, false, 1);

        return ans;
    }
};