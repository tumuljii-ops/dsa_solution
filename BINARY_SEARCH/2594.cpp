class Solution {
public:

    bool canRepair(vector<int>& ranks, int cars, long long time) {

        long long repaired = 0;

        for (int rank : ranks) {

            repaired += sqrt(time / rank);

            if (repaired >= cars) {
                return true;
            }
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        long long low = 1;

        // Worst case:
        // slowest mechanic repairs all cars
        long long high = 1LL * (*max_element(ranks.begin(), ranks.end())) 
                         * cars * cars;

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (canRepair(ranks, cars, mid)) {

                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};