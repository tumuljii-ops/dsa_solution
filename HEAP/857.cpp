class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        int n = quality.size();
        vector<pair<double, int>> workers;
        
        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap; 
        int sumQuality = 0;
        double ans = DBL_MAX;

        for (auto &w : workers) {
            double ratio = w.first;
            int q = w.second;

            maxHeap.push(q);
            sumQuality += q;

            if (maxHeap.size() > k) {
                sumQuality -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                ans = min(ans, ratio * sumQuality);
            }
        }

        return ans;
    }
};
