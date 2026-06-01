class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        // Max heap stores fuel amounts of stations
        // that we have already reached/passed.
        priority_queue<int> pq;

        int stops = 0;

        // Current maximum distance we can reach.
        long long fuel = startFuel;

        int i = 0;
        int n = stations.size();

        // Keep extending our reachable distance
        while(fuel < target) {

            // Add all stations that are reachable
            while(i < n && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);
                i++;
            }

            // No reachable station left to refuel from
            if(pq.empty()) {
                return -1;
            }

            // Refuel from the station with maximum fuel
            fuel += pq.top();
            pq.pop();

            stops++;
        }

        return stops;
    }
};