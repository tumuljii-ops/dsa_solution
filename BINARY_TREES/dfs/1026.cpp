class Solution {
public:
    int difff(TreeNode* root,int diff,int maxi,int mini){

         if(!root) return diff;

         if(root->val>maxi){
             maxi=root->val;
         } 

         if(root->val<mini){
             mini=root->val;
         }

         diff=max(diff,abs(maxi-mini));

        int x= difff(root->left,diff,maxi,mini);
        int y= difff(root->right,diff,maxi,mini);

        return max(x,y);
             
    }
    int maxAncestorDiff(TreeNode* root) {
             if(!root) return 0;
           
             int maxi=root->val;
             int mini=root->val;

             int a=difff(root->left,0,maxi,mini);
             int b=difff(root->right,0,maxi,mini);

             return max(a,b);

    }
};