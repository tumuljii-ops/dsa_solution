class Solution {
public:
    void solve(vector<string>&ans,TreeNode* root,string path){
         
          if(root==NULL){
             return ;
          }

          if(root->left==NULL && root->right==NULL){
                 ans.push_back(path);
                 return ;
          }

          if(root->left){
               solve(ans,root->left,path+"->"+to_string(root->left->val));
          }

          if(root->right){
              solve(ans,root->right,path+"->"+to_string(root->right->val));
          }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
           
            vector<string>ans;

            if(root==NULL){
                return ans;
            }

            solve(ans,root,to_string(root->val));

            return ans;
    }
};