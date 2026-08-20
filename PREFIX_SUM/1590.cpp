class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
            
            long long total_sum=0;

            for(int i=0;i<nums.size();i++){
                 total_sum=(nums[i]+total_sum)%p;

            }

            if(total_sum==0) return 0;

            long long target=total_sum;

            long long pre=0;
            int len=INT_MAX;

            unordered_map<long long,long long>mpp;

            mpp[0]=-1;

            for(int i=0;i<nums.size();i++){
                 
                  pre=(pre+nums[i])%p;

                  long long needed=(pre-target+p)%p;

                  if(mpp.find(needed)!=mpp.end()){
                     
                         int length=i-mpp[needed];

                         if(len>length){
                             len=length;
                         }
                  }

                  mpp[pre]=i;
            }

            if(len==INT_MAX || len==nums.size()){
                 return -1;
            }
            else{
                return len;
            }
    }
};