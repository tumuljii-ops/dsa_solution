class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Find length and tail
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // 2. Normalize k
        k = k % len;
        if (k == 0) return head;

        // 3. Make circular
        tail->next = head;

        // 4. Find new tail: (len - k - 1) steps
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; i++) {
            newTail = newTail->next;
        }

        // 5. Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
