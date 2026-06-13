class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<long long> power(n);

        power[0] = 1;

        for(int i=1;i<n;i++){
            power[i] = (power[i-1] * 2) % MOD;
        }

        long long answer = 0;

        for(int i=0;i<n;i++){

            int low = i;
            int high = n - 1;

            int pos = i - 1;

            while(low <= high){

                int mid = low + (high-low)/2;

                if(nums[i] + nums[mid] <= target){
                    pos = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            if(pos >= i){
                answer = (answer + power[pos-i]) % MOD;
            }
        }

        return answer;
    }
};