class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        stack<int> st;
        ListNode* temp = head;
        ListNode* temp1 = head;
        int total = 0;

        while (temp) {
            total++;
            temp = temp->next;
        }

        int reverse_pairs = total / k;
        temp = head;

        while (temp && reverse_pairs > 0) {
            int count = 0;

            while (count < k && temp) {
                st.push(temp->val);
                temp = temp->next;
                count++;
            }

            while (!st.empty()) {
                temp1->val = st.top();
                st.pop();
                temp1 = temp1->next;
            }

            reverse_pairs--;
        }

        return head;
    }
};
