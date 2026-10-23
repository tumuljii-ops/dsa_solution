class Solution {
public:
    void dfs(TreeNode* root,int val,int depth,int start){
         
             if(!root){
                 return ;
             }

             if(start+1==depth){
                  
                  TreeNode* left_node=new TreeNode(val);
                  TreeNode* right_node=new TreeNode(val);

                  if(root->left){
                     
                        TreeNode* temp=root->left;

                        root->left=left_node;
                        left_node->left=temp;
                  }
                  else{
                     root->left=left_node;
                  }

                  if(root->right){
                     TreeNode* temp=root->right;
                     root->right=right_node;
                     right_node->right=temp;
                  }
                  else{
                    root->right=right_node;
                  }
                  return ;
                  
             }

             dfs(root->left,val,depth,start+1);
             dfs(root->right,val,depth,start+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

              if(depth==1){
                  TreeNode* nodee=new TreeNode(val);
                  nodee->left=root;
                  return nodee;
              }
            
              dfs(root,val,depth,1);
              return root;
    }
};