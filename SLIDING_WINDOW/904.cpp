class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int left = 0;
        int right = 0;
        int maxlength = 0;
        int n = fruits.size();
        map<int, int> mpp;

        while (right < n) {
            mpp[fruits[right]]++;
            while (mpp.size() > k) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxlength = max(maxlength, right - left + 1);

            right++;
        }

        return maxlength;
    }
};
