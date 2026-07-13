
class Solution {
public:

    // value -> index in inorder array
    unordered_map<int,int> inorderPosition;

    TreeNode* buildSubtree(vector<int>& preorder,
                           int& preorderIndex,
                           int inorderLeft,
                           int inorderRight)
    {
        // No nodes present in this inorder range
        if(inorderLeft > inorderRight)
            return NULL;

        //--------------------------------------------------
        // Current preorder element becomes root
        //--------------------------------------------------

        int rootValue = preorder[preorderIndex];
        TreeNode* root = new TreeNode(rootValue);

        preorderIndex++;

        //--------------------------------------------------
        // Find root position in inorder
        //--------------------------------------------------

        int rootIndexInInorder = inorderPosition[rootValue];

        //--------------------------------------------------
        // Everything left of rootIndex belongs to left subtree
        //--------------------------------------------------

        root->left = buildSubtree(preorder,
                                  preorderIndex,
                                  inorderLeft,
                                  rootIndexInInorder - 1);

        //--------------------------------------------------
        // Everything right of rootIndex belongs to right subtree
        //--------------------------------------------------

        root->right = buildSubtree(preorder,
                                   preorderIndex,
                                   rootIndexInInorder + 1,
                                   inorderRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder)
    {
        int n = inorder.size();

        //--------------------------------------------------
        // Store inorder positions for O(1) lookup
        //--------------------------------------------------

        for(int i = 0; i < n; i++)
        {
            inorderPosition[inorder[i]] = i;
        }

        //--------------------------------------------------
        // Points to current root in preorder
        //--------------------------------------------------

        int preorderIndex = 0;

        return buildSubtree(preorder,
                            preorderIndex,
                            0,
                            n - 1);
    }
};