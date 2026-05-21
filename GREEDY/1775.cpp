class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {

        int sum = 0;
        int sum1 = 0;

        for(int i = 0; i < nums1.size(); i++){
            sum += nums1[i];
        }

        for(int i = 0; i < nums2.size(); i++){
            sum1 += nums2[i];
        }

        if(nums1.size() * 6 < nums2.size() ||
           nums2.size() * 6 < nums1.size()){
            return -1;
        }

        if(sum==sum1) return 0;

        vector<int> gain;

        if(sum < sum1){

            for(int i = 0; i < nums1.size(); i++){
                gain.push_back(6 - nums1[i]);
            }

            for(int i = 0; i < nums2.size(); i++){
                gain.push_back(nums2[i] - 1);
            }

        }
        else{

            for(int i = 0; i < nums2.size(); i++){
                gain.push_back(6 - nums2[i]);
            }
            
            for(int i = 0; i < nums1.size(); i++){
                gain.push_back(nums1[i] - 1);
            }
        }

        int target = abs(sum - sum1);

        sort(gain.rbegin(), gain.rend());

        int count = 0;

        for(int g : gain){

            target -= g;
            count++;

            if(target <= 0){
                return count;
            }
        }

        return -1;
    }
};