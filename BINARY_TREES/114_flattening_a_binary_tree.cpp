class Solution {
public:
    TreeNode* last_Visited=NULL;
    void flatten(TreeNode* root) {

           if(root==NULL){
            return ;
           }

           flatten(root->right);
           flatten(root->left);

           root->left=NULL;
           root->right=last_Visited;
           last_Visited=root;

    }
};