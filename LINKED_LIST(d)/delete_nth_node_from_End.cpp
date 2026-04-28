class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            temp = temp->next;
            count++;
        }
        if (count == n) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        ListNode* temp1 = head;
        for (int i = 1; i < count - n; i++) {
            temp1 = temp1->next;
        }
        ListNode* toDelete = temp1->next;
        temp1->next = temp1->next->next;
        delete toDelete;

        return head;
    }
};