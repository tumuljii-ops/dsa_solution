class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> ans(n, -1);

        long long sum = 0;

        int l = 0;

        int window = 2 * k + 1;

        for(int r = 0; r < n; r++){

            sum += nums[r];

            // maintain fixed window size
            if(r - l + 1 > window){
                sum -= nums[l];
                l++;
            }

            // valid window found
            if(r - l + 1 == window){

                int mid = l + k;

                ans[mid] = sum / window;
            }
        }

        return ans;
    }
};