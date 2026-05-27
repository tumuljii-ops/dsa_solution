/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
public:

    bool isLeaf(Node* root) {

        return (root->left == NULL &&
                root->right == NULL);
    }

    // Add left boundary
    void addLeftBoundary(Node* root,
                         vector<int>& ans) {

        Node* curr = root->left;

        while(curr) {

            if(!isLeaf(curr)) {
                ans.push_back(curr->data);
            }

            if(curr->left) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
    }

    // Add all leaf nodes
    void addLeaves(Node* root,
                   vector<int>& ans) {

        if(isLeaf(root)) {

            ans.push_back(root->data);
            return;
        }

        if(root->left) {
            addLeaves(root->left, ans);
        }

        if(root->right) {
            addLeaves(root->right, ans);
        }
    }

    // Add right boundary
    void addRightBoundary(Node* root,
                          vector<int>& ans) {

        Node* curr = root->right;

        vector<int> temp;

        while(curr) {

            if(!isLeaf(curr)) {
                temp.push_back(curr->data);
            }

            if(curr->right) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        for(int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        if(root == NULL) {
            return ans;
        }

        if(!isLeaf(root)) {
            ans.push_back(root->data);
        }

        addLeftBoundary(root, ans);

        addLeaves(root, ans);

        addRightBoundary(root, ans);

        return ans;
    }
};