class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1; 

        long long prefix = 0;
        int count = 0;

        for (int x : nums) {
            prefix += x;
            int rem = (int)(prefix % k);
            if (rem < 0) rem += k; 

            if (freq.find(rem) != freq.end()) {
                count += freq[rem]; 
            }

            freq[rem]++;
        }

        return count;
    }
};