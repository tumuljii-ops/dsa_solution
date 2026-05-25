class Solution {
public:

    long long power(long long number, long long target, long long m){

        long long ans = 1;

        for(int i = 0; i < target; i++){

            ans *= number;

            if(ans > m){
                return ans;
            }
        }

        return ans;
    }

    int nthRoot(int n, int m) {

        if(m == 0) return 0;

        int low = 1;
        int high = m;

        while(low <= high){

            int mid = (low + high) / 2;

            long long val = power(mid, n, m);

            if(val == m){
                return mid;
            }
            else if(val < m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
};