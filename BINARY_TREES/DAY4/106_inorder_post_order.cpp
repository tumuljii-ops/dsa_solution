/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            inorderMap[inorder[i]] = i;
        }
        int postIndex = n - 1;

        return build(inorder, postorder, inorderMap, 0, n - 1, postIndex);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int, int>& inorderMap,
                    int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inorderMap[rootVal];
        root->right = build(inorder, postorder, inorderMap, inIndex + 1, inEnd, postIndex);
        root->left = build(inorder, postorder, inorderMap, inStart, inIndex - 1, postIndex);

        return root;
    }
};
