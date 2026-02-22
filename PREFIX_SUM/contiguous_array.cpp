class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> mp;   // prefix -> first index
        mp[0] = -1;                  // important base case

        int prefix = 0;
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1)
                prefix += 1;
            else
                prefix -= 1;

            if(mp.find(prefix) != mp.end()) {
                int length = i - mp[prefix];
                maxLen = max(maxLen, length);
            }
            else {
                mp[prefix] = i;  // store first time we see this prefix
            }
        }

        return maxLen;
    }
};