class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end());

        int count = 1;

        long long num1 = points[0][0];
        long long num2 = points[0][1];

        for(int i = 1; i < points.size(); i++) {

            // overlap exists
            if(points[i][0] <= num2) {

                num1 = max(num1, (long long)points[i][0]);
                num2 = min(num2, (long long)points[i][1]);
            }
            else {

                count++;

                num1 = points[i][0];
                num2 = points[i][1];
            }
        }

        return count;
    }
};