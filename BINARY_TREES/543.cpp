class Solution {
public:
    int height(TreeNode* root){
          if(root==NULL) return 0;

          int left=height(root->left);
          int right=height(root->right);

          return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
           if(root==NULL) return 0;

           int left_height=diameterOfBinaryTree(root->left);
           int right_height=diameterOfBinaryTree(root->right);

           int total=height(root->left)+height(root->right);

           return max(left_height,max(right_height,total));
    }
};