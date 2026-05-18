class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> st;

        int l = 0;

        for(int r = 0; r < nums.size(); r++) {

            // window size > k
            while(r - l > k) {
                st.erase(nums[l]);
                l++;
            }

            // duplicate found
            if(st.find(nums[r]) != st.end()) {
                return true;
            }

            st.insert(nums[r]);
        }

        return false;
    }
};