class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp) {

            // check if duplicate sequence starts
            if (temp->next && temp->val == temp->next->val) {

                int val = temp->val;

                // skip all nodes with this value
                while (temp && temp->val == val) {
                    temp = temp->next;
                }

                prev->next = temp;   // remove duplicates
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};
