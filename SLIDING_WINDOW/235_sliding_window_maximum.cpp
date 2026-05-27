class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // Deque will store indices
        deque<int> dq;

        vector<int> ans;

        int n = nums.size();

        for(int i = 0; i < n; i++){

            // Remove indices that are out of current window
            // Window range = [i-k+1 , i]
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            // Remove smaller elements from back
            // because they can never become maximum
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            // Push current index
            dq.push_back(i);

            // Start storing answers when first window is formed
            if(i >= k - 1){

                // Front of deque contains maximum element index
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};