class BSTIterator {
public:
    stack<TreeNode*>st;
    
    void store(TreeNode* root){
         while(root!=NULL){
            st.push(root);
            root=root->left;
         }
    }

    BSTIterator(TreeNode* root) {
        store(root);
    }
    
    int next() {
        TreeNode* ans=st.top();
        st.pop();

        if(ans->right){
             
             store(ans->right);
        }

        return ans->val;
    }
    
    bool hasNext() {
        
        return st.size()>0;
    }
};
