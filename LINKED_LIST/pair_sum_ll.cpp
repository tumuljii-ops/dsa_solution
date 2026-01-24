class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        vector<pair<int, int>> ans;
        if (!head) return ans;

        Node* left = head;
        Node* right = head;

        while (right->next != nullptr) {
            right = right->next;
        }

  
        while (left != right && right->next != left) {

            int sum = left->data + right->data;

            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};