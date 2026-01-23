class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        stack<ListNode*> st;
        ListNode* temp = head;
        int count = 0;

        while (temp) {
            st.push(temp);
            temp = temp->next;
            count++;
        }

        temp = head;
        ListNode* nextNode = nullptr;

        for (int i = 0; i < count / 2; i++) {
            ListNode* last = st.top();
            st.pop();

            nextNode = temp->next;

            temp->next = last;
            last->next = nextNode;

            temp = nextNode;
        }

        temp->next = nullptr; 
    }
};