class Solution {
  public:
   vector<int>level(Node* root){
        
         map<int,int>mpp;
         queue<pair<Node*,int>>q;
         
         q.push({root,0});
         vector<int>ans;
         
         while(!q.empty()){
              
              Node* temp=q.front().first;
              int val=q.front().second;
              q.pop();
              
              if(mpp.find(val)==mpp.end()){
                   mpp[val]=temp->data;
              }
              else{
                  mpp[val]=temp->data;
              }
              
              if(temp->left!=NULL){
                  q.push({temp->left,val-1});
              }
              
              if(temp->right!=NULL){
                   q.push({temp->right,val+1});
              }
         }
         
         
         for(auto it:mpp){
             ans.push_back(it.second);
         }
         
         return ans;
         
   }
   
    vector<int> bottomView(Node *root) {
       
        if(root==NULL) return {};
        
        return level(root);
        
    }
};