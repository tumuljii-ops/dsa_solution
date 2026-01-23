
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        bool ans=false;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) {
                ans=true;
                break;
            }
            
        }
        if(ans==false) return 0;
        
        int count=1;
        fast=fast->next;
        while(fast!=slow){
            count++;
            fast=fast->next;
        }
        
        
        return count;
            
        
        
        
        
    }
};