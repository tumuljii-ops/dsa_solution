class Solution {
public:
    void build_graph(unordered_map<TreeNode*,vector<TreeNode*>>&adj,TreeNode* root,TreeNode* &startnode,int start){
         
           if(!root) return ;

           if(root->val==start){
               startnode=root;
           }

           if(root->left){
             
               adj[root].push_back(root->left);
               adj[root->left].push_back(root);

               build_graph(adj,root->left,startnode,start);
           }

           if(root->right){
               adj[root].push_back(root->right);
               adj[root->right].push_back(root);
               build_graph(adj,root->right,startnode,start);
           }


    }
    int amountOfTime(TreeNode* root, int start) {
         
           unordered_map<TreeNode*,vector<TreeNode*>>adj;

           TreeNode* startnode=nullptr;

           build_graph(adj,root,startnode,start);

           queue<TreeNode*>q;
           unordered_set<TreeNode*>st;
           st.insert(startnode);

           q.push(startnode);
           int time=0;

           while(!q.empty()){
                
                 int size=q.size();
                 bool burnednewnode=false;

                 for(int i=0;i<size;i++){
                     
                      TreeNode* temp=q.front();
                      q.pop();

                      for(auto &nbr:adj[temp]){
                         
                           if(st.find(nbr)==st.end()){
                                st.insert(nbr);
                                q.push(nbr);
                                burnednewnode=true;
                           }
                      }
                 }

                 if(burnednewnode){
                     time++;
                 }


           }

           return time;
    }
};