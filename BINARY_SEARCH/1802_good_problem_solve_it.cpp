class Solution {
public:

    long long getSum(long long peak, long long len) {

        if(peak > len) {

            long long last = peak - len;

            return (peak - 1 + last) * len / 2;
        }

        else {

            long long ones = len - (peak - 1);

            return (peak - 1 + 1) * (peak - 1) / 2 + ones;
        }
    }

    bool possible(int mid, int n, int index, int maxSum) {

        long long leftLen = index;
        long long rightLen = n - index - 1;

        long long leftSum = getSum(mid, leftLen);
        long long rightSum = getSum(mid, rightLen);

        long long total = leftSum + rightSum + mid;

        return total <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {

        int low = 1;
        int high = maxSum;

        int ans = 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(mid, n, index, maxSum)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};