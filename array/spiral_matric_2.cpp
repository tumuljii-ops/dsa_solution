class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
           
        vector<vector<int>> ans(n, vector<int>(n));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int count = 1;

        while(top <= bottom && left <= right){
             
            // left → right
            for(int i = left; i <= right; i++){
                ans[top][i] = count++;
            }
            top++;

            // top → bottom
            for(int j = top; j <= bottom; j++){
                ans[j][right] = count++;
            }
            right--;

            // right → left
            if(top <= bottom){
                for(int j = right; j >= left; j--){
                    ans[bottom][j] = count++;
                }
                bottom--;
            }

            // bottom → top
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans[i][left] = count++;
                }
                left++;   
            }
        }

        return ans;
    }
};
