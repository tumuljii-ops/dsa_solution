
class Solution {
public:
 
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverse(slow->next);

        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;
        bool palindrome = true;

        while (temp) {
            if (firstHalf->val != temp->val) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        slow->next = reverse(secondHalf);

        return palindrome;
    }
};