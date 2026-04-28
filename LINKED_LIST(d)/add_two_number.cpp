class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        // when both lists have nodes
        while (temp != nullptr && temp2 != nullptr) {
            int sum = temp->val + temp2->val + carry;

            ans->next = new ListNode(sum % 10);
            carry = sum / 10;

            ans = ans->next;
            temp = temp->next;
            temp2 = temp2->next;
        }

        // when l1 is longer
        while (temp != nullptr) {
            int sum = temp->val + carry;

            ans->next = new ListNode(sum % 10);
            carry = sum / 10;

            ans = ans->next;
            temp = temp->next;
        }

        // when l2 is longer
        while (temp2 != nullptr) {
            int sum = temp2->val + carry;

            ans->next = new ListNode(sum % 10);
            carry = sum / 10;

            ans = ans->next;
            temp2 = temp2->next;
        }


        if (carry) {
            ans->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
