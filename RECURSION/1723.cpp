class Solution {
public:
    int ans = INT_MAX;

    void solve(vector<int>& jobs, vector<int>& worker, int idx, int k) {

        // base case
        if(idx == jobs.size()) {
            int maxi = 0;
            for(int i = 0; i < k; i++){
                if(worker[i] > maxi){
                    maxi = worker[i];
                }
            }

            if(maxi < ans){
                ans = maxi;
            }
            return;
        }

        for(int i = 0; i < k; i++) {

            // 🔥 pruning 1: don't exceed current best
            if(worker[i] + jobs[idx] >= ans){
                continue;
            }

            // 🔥 pruning 2: avoid same empty worker states
            if(i > 0 && worker[i] == worker[i-1]){
                continue;
            }

            // assign job
            worker[i] += jobs[idx];

            solve(jobs, worker, idx + 1, k);

            // backtrack
            worker[i] -= jobs[idx];

            // 🔥 pruning 3: if this worker was empty, don't try others
            if(worker[i] == 0){
                break;
            }
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {

        // 🔥 sort descending for better pruning
        sort(jobs.rbegin(), jobs.rend());

        vector<int> worker(k, 0);

        solve(jobs, worker, 0, k);

        return ans;
    }
};
