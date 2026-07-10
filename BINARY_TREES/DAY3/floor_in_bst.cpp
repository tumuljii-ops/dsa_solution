class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
         
        int number=-1;
        
        Node* temp=root;
        
        while(temp!=NULL){
             
              if(temp->data==k){
                  return temp->data;
              }
              
              if(temp->data>k){
                  temp=temp->left;
              }
              else{
                  number=temp->data;
                  temp=temp->right;
              }
        }
        
        return number;
    }
};