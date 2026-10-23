class Solution {
public:
    long long total_sum = 0;
    long long prod = 0;
    long long MOD = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long sub_sum = root->val + left + right;

        // Yahan pehle bina modulo ke product nikalo taaki max() sahi se compare kar paaye
        long long curr_prod = sub_sum * (total_sum - sub_sum);
        
        prod = max(prod, curr_prod);
        return sub_sum;
    }

    int maxProduct(TreeNode* root) {
        if (!root) return 0;

        // Step 1: Total sum nikal lo
        total_sum = dfs(root);

        // Reset prod for the second traversal
        prod = 0;

        // Step 2: Dubara traversal karke max product dhoondho
        dfs(root);

        // Step 3: Answer return karte waqt modulo lagao
        return prod % MOD;
    }
};