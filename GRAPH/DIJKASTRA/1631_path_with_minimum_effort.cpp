class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
                
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
            
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        pq.push({0, {0,0}});

        dis[0][0] = 0;

        while(!pq.empty()) {
                  
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int i = top.second.first;
            int j = top.second.second;

            // down
            if(i + 1 < n) {

                int effort = max(
                    d,
                    abs(heights[i+1][j] - heights[i][j])
                );

                if(dis[i+1][j] > effort) {

                    dis[i+1][j] = effort;

                    pq.push({effort, {i+1, j}});
                }
            }

            // up
            if(i - 1 >= 0) {

                int effort = max(
                    d,
                    abs(heights[i-1][j] - heights[i][j])
                );

                if(dis[i-1][j] > effort) {

                    dis[i-1][j] = effort;

                    pq.push({effort, {i-1, j}});
                }
            }

            // right
            if(j + 1 < m) {

                int effort = max(
                    d,
                    abs(heights[i][j+1] - heights[i][j])
                );

                if(dis[i][j+1] > effort) {

                    dis[i][j+1] = effort;

                    pq.push({effort, {i, j+1}});
                }
            }

            // left
            if(j - 1 >= 0) {

                int effort = max(
                    d,
                    abs(heights[i][j-1] - heights[i][j])
                );

                if(dis[i][j-1] > effort) {

                    dis[i][j-1] = effort;

                    pq.push({effort, {i, j-1}});
                }
            }
        }

        return dis[n-1][m-1];
    }
};