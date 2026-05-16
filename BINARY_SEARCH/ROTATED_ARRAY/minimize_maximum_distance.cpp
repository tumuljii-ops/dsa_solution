class Solution {
public:

    // Check:
    // Can we make maximum distance <= mid
    // using at most K new stations?

    bool possible(vector<int>& stations,
                  int K,
                  double mid) {

        int count = 0;

        for (int i = 1; i < stations.size(); i++) {

            // Current gap
            double gap = stations[i] - stations[i - 1];

            // Number of new stations needed
            int needed = gap / mid;

            // If perfectly divisible
            // reduce one extra count
            if ((gap / mid) == needed * 1.0) {
                needed--;
            }

            count += needed;
        }

        // If required stations within K
        return count <= K;
    }

    double minMaxDist(vector<int>& stations, int K) {

        double low = 0;

        // Maximum possible gap initially
        double high = 0;

        for (int i = 1; i < stations.size(); i++) {

            high = max(high,
                       (double)(stations[i] - stations[i - 1]));
        }

        // Precision for decimal binary search
        double diff = 1e-6;

        while ((high - low) > diff) {

            double mid = low + (high - low) / 2.0;

            // If this maximum distance is possible
            if (possible(stations, K, mid)) {

                // Try smaller answer
                high = mid;
            }
            else {

                // Need bigger maximum distance
                low = mid;
            }
        }

        return high;
    }
};