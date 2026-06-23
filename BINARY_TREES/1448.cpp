class Solution {
public:

    int dfs(TreeNode* root, int maxi){

        if(root == NULL){
            return 0;
        }

        int count = 0;

        if(root->val >= maxi){
            count = 1;
        }

        maxi = max(maxi, root->val);

        int left = dfs(root->left, maxi);
        int right = dfs(root->right, maxi);

        return count + left + right;
    }

    int goodNodes(TreeNode* root) {

        return dfs(root, root->val);
    }
};