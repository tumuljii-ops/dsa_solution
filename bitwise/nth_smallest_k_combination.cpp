class Solution {
public:
    // This table will store combinations: C[n][k]
    long long C[55][55];

    // Function to precompute combinations using Pascal's triangle
    void buildCombinations() {

        // Loop through possible values
        for (int i = 0; i <= 50; i++) {

            // Base cases:
            // C(i,0) = 1  and  C(i,i) = 1
            C[i][0] = 1;
            C[i][i] = 1;

            // Fill remaining values
            for (int j = 1; j < i; j++) {
                // Combination formula:
                // C(i,j) = C(i-1,j-1) + C(i-1,j)
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    long long nthSmallest(long long n, int k) {

        // Precompute all combinations
        buildCombinations();

        // This will store our final answer
        long long answer = 0;

        // Maximum bits because answer < 2^50
        int maxBits = 50;

        // We construct the number from most significant bit to least
        for (int i = maxBits; i >= 0; i--) {

            // If no more 1s are needed, we can stop
            if (k == 0) {
                break;
            }

            // Count how many valid numbers we can make
            // if we keep the current bit as 0
            long long waysIfZero;

            // If we have enough remaining positions to place k ones
            if (i >= k) {
                waysIfZero = C[i][k];
            }
            // Otherwise it is impossible
            else {
                waysIfZero = 0;
            }

            // If keeping this bit as 0 gives enough numbers
            if (waysIfZero >= n) {
                // We keep this bit as 0
                // Just move to the next bit
                continue;
            }
            // Otherwise, we must place a 1 here
            else {

                // Skip all numbers that start with 0 at this bit
                n = n - waysIfZero;

                // Set the current bit to 1
                answer = answer + (1LL << i);

                // One '1' is used
                k = k - 1;
            }
        }

        // Return the constructed number
        return answer;
    }
};
