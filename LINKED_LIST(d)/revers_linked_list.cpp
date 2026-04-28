class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* ahead = nullptr;  

        while (current != nullptr) {

            ahead = current->next;   

            current->next = prev;
            prev = current;

            current = ahead;
        }

        return prev;                 
    }
};