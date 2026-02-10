class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = nums[i] + ans[i - 1];
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (ans[i] == k) count++;
        }

        int i = 0;
        int j = 1;

        while (i < n && j < n) {
            if (ans[j] - ans[i] == k) {
                count++;
                i++;
                j = i + 1;
            }
            else if (ans[j] - ans[i] > k) {
                i++;
                j = i + 1;
            }
            else {
                j++;
            }
        }

        return count;
    }
};
