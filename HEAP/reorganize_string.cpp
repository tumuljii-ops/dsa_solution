class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        
        for (char ch : tasks) {
            mpp[ch]++;
        }

        priority_queue<pair<int,char>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        int time = 0;
        while (!pq.empty()) {
            vector<pair<int,char>> temp;
            int cycle = n + 1;

            while (cycle > 0 && !pq.empty()) {
                auto top = pq.top();
                pq.pop();

                time++;
                if (top.first - 1 > 0) {
                    temp.push_back({top.first - 1, top.second});
                }
                cycle--;
            }

            for (auto p : temp) {
                pq.push(p);
            }

            if (!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};
