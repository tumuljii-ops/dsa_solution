class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;

        while (temp && temp->next) {

            if (temp->val == temp->next->val) {
                ListNode* temp1 = temp->next;
                temp->next = temp->next->next;
                delete temp1;
            } 
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};
