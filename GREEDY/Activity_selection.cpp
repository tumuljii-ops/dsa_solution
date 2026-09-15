class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();

        // Pair as {finish_time, start_time} for default sorting by finish time
        vector<pair<int, int>> activities(n);
        for (int i = 0; i < n; i++) {
            activities[i] = {finish[i], start[i]};
        }

        // Sort by finish time ascending
        sort(activities.begin(), activities.end());

        int count = 1;
        int last_finish_time = activities[0].first;

        // Greedily pick the next activity that starts strictly after (or at) last_finish_time
        for (int i = 1; i < n; i++) {
            if (activities[i].second > last_finish_time) { // Use >= if touching endpoints are allowed
                count++;
                last_finish_time = activities[i].first;
            }
        }

        return count;
    }
};