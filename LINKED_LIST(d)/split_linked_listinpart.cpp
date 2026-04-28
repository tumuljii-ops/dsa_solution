class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        ListNode* temp = head;
        int count = 0;

        while (temp) {
            count++;
            temp = temp->next;
        }

        int total = count / k;
        int modulo = count % k;

        vector<ListNode*> ans;
        temp = head;  

        for (int i = 0; i < k; i++) {
            ListNode* partHead = temp;
            int partSize = total + (modulo > 0 ? 1 : 0);

            modulo--;

            for (int j = 0; j < partSize - 1 && temp; j++) {
                temp = temp->next;
            }

            if (temp) {
                ListNode* nextPart = temp->next;
                temp->next = nullptr;
                temp = nextPart;
            }

            ans.push_back(partHead);
        }

        return ans;
    }
};