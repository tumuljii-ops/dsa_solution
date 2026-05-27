class Solution {
public:
    double gain(int pass, int total) {

        double curr = (double)pass / total;

        double next = (double)(pass + 1) / (total + 1);

        return next - curr;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<vector<double>> pq;

        for(int i = 0; i < classes.size(); i++) {

            int pass = classes[i][0];
            int total = classes[i][1];

            pq.push({gain(pass, total),
                     (double)pass,
                     (double)total});
        }

        while(extraStudents--) {

            auto top = pq.top();
            pq.pop();

            int pass = top[1];
            int total = top[2];
            pass++;
            total++;

            pq.push({gain(pass, total),
                     (double)pass,
                     (double)total});
        }

        double ans = 0.0;

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            double pass = top[1];
            double total = top[2];

            ans += (pass / total);
        }

        return ans / classes.size();
    }
};