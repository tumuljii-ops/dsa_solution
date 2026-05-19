class Solution {
public:

    bool possible(vector<int>& candies, long long k, int mid){

        long long children = 0;

        for(int i = 0; i < candies.size(); i++){

            children += candies[i] / mid;

            if(children >= k){
                return true;
            }
        }

        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {

        int low = 1;

        int high = *max_element(candies.begin(), candies.end());

        int ans = 0;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(possible(candies, k, mid)){

                ans = mid;

                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};