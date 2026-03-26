class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;

        for (int num : nums) {
            xorr = xorr ^ num;
        }

        int setbit = xorr & (-xorr);

        int a = 0;
        int b = 0;

        for (int num : nums) {
            if ((num & setbit) != 0) {
                a = a ^ num;
            } else {
                b = b ^ num;
            }
        }

        return {a, b};
    }
};