class Solution {
public:

    // This function checks:
    // "Can we place k cows such that
    // minimum distance between any two cows is at least mid ?"

    bool possible(vector<int>& stalls, int k, int mid) {

        // Place first cow at first stall
        int laststallpos = stalls[0];

        // One cow already placed
        int cow = 1;

        // Try placing remaining cows
        for (int i = 1; i < stalls.size(); i++) {

            // If current stall is far enough from last placed cow
            if (stalls[i] - laststallpos >= mid) {

                // Place cow here
                cow++;

                // Update last placed cow position
                laststallpos = stalls[i];
            }

            // If all cows placed successfully
            // then this minimum distance is possible
            if (cow == k) {
                return true;
            }
        }

        // Could not place all cows
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {

        // Sort stalls because distance logic
        // only works properly in sorted order
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();

        // We are binary searching on ANSWER

        // Minimum possible distance
        int low = 1;

        // Maximum possible distance
        // between first and last stall
        int high = stalls[n - 1] - stalls[0];

        // Store best valid answer
        int ans = 0;

        while (low <= high) {

            // Candidate minimum distance
            int mid = low + (high - low) / 2;

            // Check if this distance is possible
            if (possible(stalls, k, mid)) {

                // mid is a valid answer
                ans = mid;

                // Try for bigger minimum distance
                // because we want MAXIMUM minimum distance
                low = mid + 1;
            }
            else {

                // mid is not possible
                // so reduce distance
                high = mid - 1;
            }
        }

        return ans;
    }
};