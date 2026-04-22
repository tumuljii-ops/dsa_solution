class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]&(1<<i)){
                    count++;
                }
            }
            if(count%3==1){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};