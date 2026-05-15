class Solution {
public:

    void generate(int ind, int sum, vector<int>& arr, vector<int>& sums) {

        // Base case
        if(ind == arr.size()) {
            sums.push_back(sum);
            return;
        }

        // Take current element
        generate(ind + 1, sum + arr[ind], arr, sums);

        // Do not take current element
        generate(ind + 1, sum, arr, sums);
    }

    int minAbsDifference(vector<int>& nums, int goal) {

        int n = nums.size();

        // Split array into two halves
        vector<int> left(nums.begin(), nums.begin() + n / 2);

        vector<int> right(nums.begin() + n / 2, nums.end());

        vector<int> leftSums;
        vector<int> rightSums;

        // Generate all subset sums
        generate(0, 0, left, leftSums);
        generate(0, 0, right, rightSums);

        // Sort right sums for binary search
        sort(rightSums.begin(), rightSums.end());

        int ans = INT_MAX;

        // Try every left sum
        for(int x : leftSums) {

            int target = goal - x;

            auto it = lower_bound(rightSums.begin(),
                                  rightSums.end(),
                                  target);

            // Check current iterator
            if(it != rightSums.end()) {

                ans = min(ans,
                          abs(x + *it - goal));
            }

            // Check previous iterator
            if(it != rightSums.begin()) {

                it--;

                ans = min(ans,
                          abs(x + *it - goal));
            }
        }

        return ans;
    }
};