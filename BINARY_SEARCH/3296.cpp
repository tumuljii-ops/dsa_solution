class Solution {
public:
    bool canFinish(long long mid, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;

        for (int i = 0; i < workerTimes.size(); i++) {
            long long t = workerTimes[i];

            long long low = 0;
            long long high = mountainHeight;
            long long best = 0;

            while (low <= high) {
                long long k = low + (high - low) / 2;
                long long requiredTime = t * k * (k + 1) / 2;

                if (requiredTime <= mid) {
                    best = k;
                    low = k + 1;
                } else {
                    high = k - 1;
                }
            }

            total += best;

            if (total >= mountainHeight) {
                return true;
            }
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long fastest = *min_element(workerTimes.begin(), workerTimes.end());
        long long high = fastest * 1LL * mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canFinish(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};