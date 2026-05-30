class Solution {
public:

    void dfs(TreeNode* root, int curr, int &sum) {
        
        if(root == NULL)
            return;

        curr = curr * 10 + root->val;

        if(root->left == NULL && root->right == NULL) {
            sum += curr;
            return;
        }

        dfs(root->left, curr, sum);
        dfs(root->right, curr, sum);
    }

    int sumNumbers(TreeNode* root) {
        
        int sum = 0;

        dfs(root, 0, sum);

        return sum;
    }
};