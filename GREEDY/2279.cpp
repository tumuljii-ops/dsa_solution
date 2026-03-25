class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back(capacity[i] - rocks[i]);
        }

        sort(arr.begin(), arr.end());

        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= additionalRocks) {
                additionalRocks = additionalRocks - arr[i];
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};