class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int curMax = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        while (true) {
            auto cur = pq.top();
            pq.pop();

            int curMin = cur[0];
            int listIdx = cur[1];
            int elemIdx = cur[2];

            if (curMax - curMin < end - start) {
                start = curMin;
                end = curMax;
            }

            if (elemIdx + 1 == nums[listIdx].size())
                break;

            int nextVal = nums[listIdx][elemIdx + 1];
            pq.push({nextVal, listIdx, elemIdx + 1});
            curMax = max(curMax, nextVal);
        }

        return {start, end};
    }
};
