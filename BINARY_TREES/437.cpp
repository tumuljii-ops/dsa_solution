class Solution {
public:

    int dfs(TreeNode* root,
            long long currSum,
            int targetSum,
            unordered_map<long long,int>& mpp)
    {
        if(root == NULL) {
            return 0;
        }

        currSum += root->val;

        int count = 0;

        // paths ending at current node
        if(mpp.count(currSum - targetSum)) {
            count += mpp[currSum - targetSum];
        }

        mpp[currSum]++;

        count += dfs(root->left,
                     currSum,
                     targetSum,
                     mpp);

        count += dfs(root->right,
                     currSum,
                     targetSum,
                     mpp);

        // backtrack
        mpp[currSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long long,int> mpp;

        // important
        mpp[0] = 1;

        return dfs(root,0,targetSum,mpp);
    }
};