class Solution {
public:
    TreeNode* dfs(TreeNode* root){
         
            if(!root){
                return nullptr;
            }

            root->left=dfs(root->left);
            root->right=dfs(root->right);

            if(root->left==NULL && root->right==NULL){
                 
                       if(root->val==0){
                            return nullptr;
                       }
            }

            return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
           
           root=dfs(root);

           return root;
    }
};