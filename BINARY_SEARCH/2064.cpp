class Solution {
public:

    bool possible(int mid, int n, vector<int>& quantities){

        long long total = 0;

        for(int i = 0; i < quantities.size(); i++){

            total += (quantities[i] + mid - 1) / mid;

            if(total > n){
                return false;
            }
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;

        int high = *max_element(quantities.begin(), quantities.end());

        int ans = high;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(possible(mid, n, quantities)){

                ans = mid;

                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};