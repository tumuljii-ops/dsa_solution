/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           
             vector<vector<int>>answer;

             if(root==NULL){
                 return answer;
             }

             queue<TreeNode*>q;

             q.push(root);

             bool right=true;

             while(!q.empty()){
                 
                   int size=q.size();

                   vector<int>ans;

                   for(int i=0;i<size;i++){
                     
                         TreeNode* temp=q.front();
                         q.pop();

                         ans.push_back(temp->val);

                         if(temp->left){
                             q.push(temp->left);

                         }

                         if(temp->right){
                             
                              q.push(temp->right);
                         }


                   }

                   if(right==false){
                      reverse(ans.begin(),ans.end());
                      answer.push_back(ans);
                      right=true;
                   }
                   else{
                       answer.push_back(ans);
                       right=false;

                   }
                      
             }

             return answer;
    }
};