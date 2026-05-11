class Solution {
public:

    int longestBitonicSequence(int n, vector<int> &nums) {

        vector<int> lis(n, 1);

        // LIS
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[i] > nums[j]) {

                    lis[i] = max(lis[i],
                                 1 + lis[j]);
                }
            }
        }

        vector<int> lds(n, 1);

        // LDS
        for(int i = n - 1; i >= 0; i--) {

            for(int j = n - 1; j > i; j--) {

                if(nums[i] > nums[j]) {

                    lds[i] = max(lds[i],
                                 1 + lds[j]);
                }
            }
        }

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            maxi = max(maxi,
                       lis[i] + lds[i] - 1);
        }

        return maxi;
    }
};
