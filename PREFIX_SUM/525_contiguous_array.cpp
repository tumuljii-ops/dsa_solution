class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans[i]=-1;
            }
            else{
                ans[i]=1;
            }
        }

        unordered_map<int,int>mpp;
        int prefixsum=0;
        mpp[0]=-1;
        int maxlen=0;

        for(int i=0;i<ans.size();i++){
            prefixsum=prefixsum+ans[i];

            if(mpp.find(prefixsum)!=mpp.end()){
              maxlen=max(maxlen,(i-mpp[prefixsum]));
            }
            else{
             mpp[prefixsum]=i;
             }
        }

        return maxlen;

    }
};