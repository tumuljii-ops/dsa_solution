class Solution {
public:
    bool selfdividing(int number) {
        int original = number;

        while (number > 0) {
            int digit = number % 10;

            if (digit == 0 || original % digit != 0)
                return false;

            number /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            if (selfdividing(i))
                ans.push_back(i);
        }
        return ans;
    }
};
