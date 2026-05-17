class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        // Always apply binary search on smaller array
        // to keep complexity minimum
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while (low <= high) {

            // Number of elements taken from nums1
            int cut1 = low + (high - low) / 2;

            // Remaining elements taken from nums2
            // so total left side has half elements
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Left element from nums1
            // If no element on left side
            // take -infinity
            int l1;

            if (cut1 == 0) {
                l1 = INT_MIN;
            }
            else {
                l1 = nums1[cut1 - 1];
            }

            // Left element from nums2
            int l2;

            if (cut2 == 0) {
                l2 = INT_MIN;
            }
            else {
                l2 = nums2[cut2 - 1];
            }

            // Right element from nums1
            // If no element on right side
            // take +infinity
            int r1;

            if (cut1 == n1) {
                r1 = INT_MAX;
            }
            else {
                r1 = nums1[cut1];
            }

            // Right element from nums2
            int r2;

            if (cut2 == n2) {
                r2 = INT_MAX;
            }
            else {
                r2 = nums2[cut2];
            }

            // Correct partition found
            // Every left element <= every right element
            if (l1 <= r2 && l2 <= r1) {

                // Odd total elements
                // Median is maximum element of left side
                if ((n1 + n2) % 2 == 1) {

                    return max(l1, l2);
                }

                // Even total elements
                // Median is average of:
                // max left + min right
                else {

                    return (max(l1, l2)
                           + min(r1, r2)) / 2.0;
                }
            }

            // Too many elements taken from nums1
            // Move left
            else if (l1 > r2) {

                high = cut1 - 1;
            }

            // Too few elements taken from nums1
            // Move right
            else {

                low = cut1 + 1;
            }
        }

        return 0;
    }
};