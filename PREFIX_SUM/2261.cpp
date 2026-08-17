class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> distinctSubarrays;
        int n = nums.size();

        for (int left = 0; left < n; ++left) {
            int count = 0;
            vector<int> current;

            for (int right = left; right < n; ++right) {
                if (nums[right] % p == 0) {
                    count++;
                }

                if (count > k) {
                    break; 
                }

                current.push_back(nums[right]);
                distinctSubarrays.insert(current);
            }
        }

        return distinctSubarrays.size();
    }
};