class Solution {
public:
    bool check(int x, int n) {
        long long left = (long long)x * (x + 1) / 2;
        long long right = (long long)(n + x) * (n - x + 1) / 2;
        return left == right;
    }

    int pivotInteger(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long left = (long long)mid * (mid + 1) / 2;
            long long right = (long long)(n + mid) * (n - mid + 1) / 2;

            if (left == right) return mid;
            else if (left < right) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};
