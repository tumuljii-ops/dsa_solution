class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

                int count_even=0;
                int count_odd=0;

                for(int i=0;i<nums1.size();i++){
                     if(nums1[i]%2==0) count_even++;
                     else count_odd++;
                }  

                if(count_even==nums1.size()||count_odd==nums1.size()) return true;

                int mini=INT_MAX;
                for(int i=0;i<nums1.size();i++){
                    if(nums1[i]%2==1){
                        if(mini>nums1[i]){
                            mini=nums1[i];
                        }
                    }
                }

                for(int i=0;i<nums1.size();i++){
                    if(nums1[i]%2==0){
                        if(nums1[i]-mini<1){
                            return false;
                        }
                    }
                }

                return true;


    } 
};