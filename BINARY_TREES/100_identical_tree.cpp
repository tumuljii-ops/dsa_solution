class Solution {
public:
    bool isidentical(TreeNode* root,TreeNode* subRoot){
         
          if(root==NULL || subRoot==NULL) return root==subRoot;

          bool left_tree=isidentical(root->left,subRoot->left);
          bool right_tree=isidentical(root->right,subRoot->right);
          
          return left_tree && right_tree && root->val ==subRoot->val;


    }

};