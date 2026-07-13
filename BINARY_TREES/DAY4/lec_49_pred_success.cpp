class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        
        Node* pred = NULL;
        Node* suc = NULL;
        
        Node* temp = root;
        
        // Find predecessor
        while(temp != NULL){
            
            if(temp->data < key){
                pred = temp;
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        
        temp = root;
        
        // Find successor
        while(temp != NULL){
            
            if(temp->data > key){
                suc = temp;
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        
        return {pred, suc};
    }
};