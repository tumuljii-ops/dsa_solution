class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* dummy = new ListNode(0); 
        ListNode* tempp = dummy;

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                tempp->next = new ListNode(temp1->val);
                temp1 = temp1->next;
            } else {
                tempp->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            tempp = tempp->next;
        }
        while (temp1 != nullptr) {
            tempp->next = new ListNode(temp1->val);
            temp1 = temp1->next;
            tempp = tempp->next;
        }
        while (temp2 != nullptr) {
            tempp->next = new ListNode(temp2->val);
            temp2 = temp2->next;
            tempp = tempp->next;
        }

        return dummy->next;
    }
};