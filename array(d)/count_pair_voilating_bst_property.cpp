class Solution {
  public:
    long long merge(vector<int>& ans, vector<int>& temp, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;
        long long inv_count = 0;
        
        while (i <= mid && j <= right) { // Fixed: j <= right
            if (ans[i] <= ans[j]) {
                temp[k++] = ans[i++];
            } else {
                inv_count += (mid - i + 1);
                temp[k++] = ans[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = ans[i++];
        }
        
        while (j <= right) {
            temp[k++] = ans[j++];
        }
        
        for (int idx = left; idx <= right; idx++) {
            ans[idx] = temp[idx];
        }
        
        return inv_count;
    }
    
    long long merge_sort(vector<int>& ans, vector<int>& temp, int left, int right) {
        long long inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            inv_count += merge_sort(ans, temp, left, mid);
            inv_count += merge_sort(ans, temp, mid + 1, right);
            inv_count += merge(ans, temp, left, mid, right);
        }
        return inv_count;
    }
    
    void inorder(vector<int>& ans, Node* root) {
        if (!root) return;
        
        inorder(ans, root->left);
        ans.push_back(root->data);
        inorder(ans, root->right);
    }
    
    int pairsViolatingBST(Node* root) {
        vector<int> ans;
        inorder(ans, root);
        
        int n = ans.size();
        vector<int> temp(n);
        
        long long x = merge_sort(ans, temp, 0, n - 1);
        return x; // Return long long directly or cast to int if required by signature
    }
};