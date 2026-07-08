class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || issymmetricornot(root->left, root->right);
    }

    bool issymmetricornot(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) {
            return left == right;  
        }
        if (left->val != right->val) {
            return false;
        }
        return issymmetricornot(left->left, right->right) &&
               issymmetricornot(left->right, right->left);
    }
};
