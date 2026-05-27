class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int prefixsum=0;
        int good=2;
        mpp[0]=-1;

        for(int i=0;i<nums.size();i++){
            prefixsum=prefixsum+nums[i];
            
            int rem=(prefixsum%k);
            if(rem<0) rem=rem+k;

            if(mpp.find(rem)!=mpp.end()){
               if(i-mpp[rem]>=good) return true;
            }
            else {
            mpp[rem]=i;
            }
           
            
            
        }

        return false;

    }
};