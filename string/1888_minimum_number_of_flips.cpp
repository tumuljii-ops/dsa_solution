class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        int diff1 = 0;
        int diff2 = 0;
        int ans = n;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {
            char chRight = s[right % n];

            char expected1Right;
            if (right % 2 == 0) {
                expected1Right = '0';
            } else {
                expected1Right = '1';
            }

            char expected2Right;
            if (right % 2 == 0) {
                expected2Right = '1';
            } else {
                expected2Right = '0';
            }

            if (chRight != expected1Right) {
                diff1++;
            }
            if (chRight != expected2Right) {
                diff2++;
            }

            if (right - left + 1 > n) {
                char chLeft = s[left % n];

                char expected1Left;
                if (left % 2 == 0) {
                    expected1Left = '0';
                } else {
                    expected1Left = '1';
                }

                char expected2Left;
                if (left % 2 == 0) {
                    expected2Left = '1';
                } else {
                    expected2Left = '0';
                }

                if (chLeft != expected1Left) {
                    diff1--;
                }
                if (chLeft != expected2Left) {
                    diff2--;
                }

                left++;
            }

            if (right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};