class Solution {
  public:

    int ans;

    void reverseInorder(Node* root, int &k) {

        if(root == NULL)
            return;

        // right
        reverseInorder(root->right, k);

        // root
        k--;

        if(k == 0) {
            ans = root->data;
            return;
        }

        // left
        reverseInorder(root->left, k);
    }

    int kthLargest(Node *root, int k) {

        reverseInorder(root, k);

        return ans;
    }
};