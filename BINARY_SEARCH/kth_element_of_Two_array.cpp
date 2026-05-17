class Solution {
public:

    int kthElement(vector<int>& a,
                   vector<int>& b,
                   int k) {

        // Always binary search on smaller array
        // to reduce complexity
        if (a.size() > b.size()) {
            return kthElement(b, a, k);
        }

        int n1 = a.size();
        int n2 = b.size();

        // Minimum elements we can take from a
        // because remaining must come from b
        int low = max(0, k - n2);

        // Maximum elements we can take from a
        int high = min(k, n1);

        while (low <= high) {

            // Elements taken from a
            int cut1 = low + (high - low) / 2;

            // Remaining elements taken from b
            int cut2 = k - cut1;

            // Left element from a
            int l1;

            if (cut1 == 0) {
                l1 = INT_MIN;
            }
            else {
                l1 = a[cut1 - 1];
            }

            // Left element from b
            int l2;

            if (cut2 == 0) {
                l2 = INT_MIN;
            }
            else {
                l2 = b[cut2 - 1];
            }

            // Right element from a
            int r1;

            if (cut1 == n1) {
                r1 = INT_MAX;
            }
            else {
                r1 = a[cut1];
            }

            // Right element from b
            int r2;

            if (cut2 == n2) {
                r2 = INT_MAX;
            }
            else {
                r2 = b[cut2];
            }

            // Correct partition found
            if (l1 <= r2 && l2 <= r1) {

                // kth element is largest element
                // on left side
                return max(l1, l2);
            }

            // Too many elements taken from a
            // move left
            else if (l1 > r2) {

                high = cut1 - 1;
            }

            // Too few elements taken from a
            // move right
            else {

                low = cut1 + 1;
            }
        }

        return -1;
    }
};