class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
        ListNode* temp1=headB;

        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }

        int count1=0;
        while(temp1){
            count1++;
            temp1=temp1->next;
        }
        temp=headA;
        temp1=headB;

        if(count<count1){
             while(count!=count1){
                temp1=temp1->next;
                count++;

             }
        }
        else{
            while(count1!=count){
                temp=temp->next;
                count1++;
            }
        }

        while(temp && temp1){
            if(temp==temp1){
                return temp;
               
            }
            temp=temp->next;
            temp1=temp1->next;
        }

        return nullptr;

    }
};