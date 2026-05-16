class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int numRows = arr.size();
        int numCols = arr[0].size();
        int currentRow = 0;
        int currentCol = numCols - 1;
        int maxRowIndex = -1;

        // Traverse the matrix starting from the top-right corner
        while (currentRow < numRows && currentCol >= 0) {
            if (arr[currentRow][currentCol] == 1) {
                maxRowIndex = currentRow;

                // Move left if a 1 is found
                currentCol--;
            } else {

                // Move down if a 0 is found
                currentRow++;
            }
        }

        return maxRowIndex;
    }
};