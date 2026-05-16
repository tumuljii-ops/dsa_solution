class Solution {
    bool binary_search(vector<int>& ans, int x) {
        int low = 0;                       
        int high = ans.size() - 1;        

        while (low <= high) {
            int mid = (low + high) / 2;
            if (ans[mid] == x) {
                return true;
            }
            if (ans[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] <= target && matrix[i][m - 1] >= target) {
                return binary_search(matrix[i], target);
            }
        }

        return false;
    }
};
