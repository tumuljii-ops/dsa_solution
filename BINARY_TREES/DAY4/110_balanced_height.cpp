class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
    int dfs(TreeNode* root){
           if(root==NULL){
            return 0;
           }
           int leftheight=dfs(root->left);
           if(leftheight==-1) return -1;
           int rightheight=dfs(root->right);
           if(rightheight==-1) return -1;
           if(abs(leftheight-rightheight)>1) return -1;
           return max(leftheight,rightheight)+1;
    }
};