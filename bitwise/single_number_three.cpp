class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
           
           int xorr=0;

           for(int i=0;i<nums.size();i++){
               xorr=xorr^nums[i];
           }

           long long setbit=(long long)xorr & (-(long long)xorr);

           int a=0;
           int b=0;

           for(auto num:nums){
               
                if((num&setbit)!=0){
                     a=a^num;
                }
                else{
                    b=b^num;
                }
           }

           return {a,b};

    }
};