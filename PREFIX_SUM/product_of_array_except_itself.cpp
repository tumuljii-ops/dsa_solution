class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
             int n=nums.size();

             vector<int>prefix(n,1);
             vector<int>suffix(n,1);

             for(int i=1;i<n;i++){
                   long long prod=1LL*prefix[i-1]*nums[i-1];
                   prefix[i]=prod;
             }

             for(int i=n-2;i>=0;i--){
                  long long prod1=1LL*suffix[i+1]*nums[i+1];
                  suffix[i]=prod1;
             }

             vector<int>ans;

             for(int i=0;i<n;i++){
                long long answer=1LL*prefix[i]*suffix[i];
                ans.push_back(answer);
             }

             return ans;

    }
};