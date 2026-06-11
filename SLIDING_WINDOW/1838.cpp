class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

           sort(nums.begin(),nums.end());

           long long sum=0;
           int l=0;
           int r=0;
           int ans=1;
           int n=nums.size();

          while(r<n){
              sum+=nums[r];

              while((long long)nums[r]*(r-l+1)-sum>k){
                    sum-=nums[l];
                    l++;
              }

              ans=max(ans,r-l+1);
              r++;
          }

        return ans;
    }
};