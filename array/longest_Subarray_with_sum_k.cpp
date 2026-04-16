class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int sum = 0;
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            
            sum += arr[i];
            
            // case 1: subarray from 0 to i
            if(sum == k) {
                maxi = i + 1;
            }
            
            // case 2: subarray from somewhere in middle
            if(mp.find(sum - k) != mp.end()) {
                int len = i - mp[sum - k];
                maxi = max(maxi, len);
            }
            
            // store first occurrence
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return maxi;
    }
};
