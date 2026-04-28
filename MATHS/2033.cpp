class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
              
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;
        
        int base = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if((grid[i][j] - base) % x != 0){
                    return -1;
                }

                ans.push_back(grid[i][j]);
            }
        }

        sort(ans.begin(), ans.end());

        int median = ans[ans.size() / 2];

        int total = 0;

        for(int i = 0; i < ans.size(); i++){
            total += abs(ans[i] - median) / x;
        }

        return total;
    }
};
