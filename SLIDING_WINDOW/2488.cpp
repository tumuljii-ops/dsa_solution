class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int n = nums.size();

        int idx = 0;

        while(nums[idx]!=k)
            idx++;

        int balance = 0;

        mp[0] = 1;

        // Right side
        for(int i=idx+1;i<n;i++){

            if(nums[i]>k)
                balance++;

            else
                balance--;

            mp[balance]++;
        }

        int ans = 0;

        balance = 0;

        // Left side
        for(int i=idx;i>=0;i--){

            if(nums[i]>k)
                balance++;

            else if(nums[i]<k)
                balance--;

            ans += mp[-balance];
            ans += mp[1-balance];
        }

        return ans;
    }
};