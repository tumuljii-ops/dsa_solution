class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        int carry=root->val;
        if(carry<p->val && carry<q->val){
        return lowestCommonAncestor(root->right,p,q);
        }
        if(carry>p->val && carry>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
        
    }
};