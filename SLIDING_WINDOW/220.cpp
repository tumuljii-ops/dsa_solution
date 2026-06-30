class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        vector<pair<long long, int>> vec;

        // Store (value, original index)
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], i});
        }

        // Sort by value
        sort(vec.begin(), vec.end());

        set<int> st;      // Stores indices in current value window
        int left = 0;

        for (int right = 0; right < vec.size(); right++) {

            while (vec[right].first - vec[left].first > valueDiff) {
                st.erase(vec[left].second);
                left++;
            }

            int idx = vec[right].second;

            // Find first index >= idx - indexDiff
            auto it = st.lower_bound(idx - indexDiff);

            // Check if it lies within idx + indexDiff
            if (it != st.end() && *it <= idx + indexDiff)
                return true;

            // Insert current index
            st.insert(idx);
        }

        return false;
    }
};