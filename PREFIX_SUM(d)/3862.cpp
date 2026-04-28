class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> leftSum(n, 0);
        vector<long long> rightProd(n, 1);

        long long totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }

        // leftSum[i] = sum of elements strictly left of i
        for (int i = 1; i < n; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        // rightProd[i] = product of elements strictly right of i
        for (int i = n - 2; i >= 0; i--) {
            if (rightProd[i + 1] > totalSum / nums[i + 1]) {
                rightProd[i] = totalSum + 1;  
            } else {
                rightProd[i] = rightProd[i + 1] * nums[i + 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (leftSum[i] == rightProd[i]) {
                return i;
            }
        }

        return -1;
    }
};