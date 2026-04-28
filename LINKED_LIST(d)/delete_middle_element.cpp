class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* dummy=new ListNode();
        dummy->next=head;

        ListNode* temp3=dummy;
        int count=0;

        while(temp2!=nullptr && temp2->next!=nullptr){
            temp1=temp1->next;
            temp2=temp2->next->next;
            temp3=temp3->next;
            count++;
        } 

        if(count==0) return nullptr;

        temp3->next=temp1->next;
        delete(temp1);

        return head;

    }
};