class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        // Deque for maintaining maximum elements
        deque<int> maxDeque;

        // Deque for maintaining minimum elements
        deque<int> minDeque;

        int left = 0;

        int ans = 0;

        for(int right = 0; right < nums.size(); right++){

            // Maintain decreasing order for maximum deque
            while(!maxDeque.empty() && nums[maxDeque.back()] < nums[right]){
                maxDeque.pop_back();
            }

            // Add current index
            maxDeque.push_back(right);

            // Maintain increasing order for minimum deque
            while(!minDeque.empty() && nums[minDeque.back()] > nums[right]){
                minDeque.pop_back();
            }

            // Add current index
            minDeque.push_back(right);

            // Shrink window if condition breaks
            while(nums[maxDeque.front()] - nums[minDeque.front()] > limit){

                // Remove left index if out of window
                if(maxDeque.front() == left){
                    maxDeque.pop_front();
                }

                // Remove left index if out of window
                if(minDeque.front() == left){
                    minDeque.pop_front();
                }

                left++;
            }

            // Update maximum window size
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};