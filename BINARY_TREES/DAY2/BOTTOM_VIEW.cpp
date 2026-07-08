class Solution {
  public:
    
    vector<int>bottom(Node* root){
         
          vector<int>ans;
          
          map<int,int>mpp;
          
          queue<pair<Node*,int>>q;
          
          q.push({root,0});
          
          while(!q.empty()){
               
               Node* temp=q.front().first;
               int dist=q.front().second;
               q.pop();
               
               mpp[dist]=temp->data;
               
               if(temp->left){
                   q.push({temp->left,dist-1});
               }
               
               if(temp->right){
                   q.push({temp->right,dist+1});
               }
          }
          
          for(auto it:mpp){
              ans.push_back(it.second);
          }
          
          return ans;
          
    }
    vector<int> bottomView(Node *root) {
          
          if(root==NULL){
               return {};
               
             
          }
          
          return bottom(root);
        
    }
};