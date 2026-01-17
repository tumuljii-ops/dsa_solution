class Solution {
public:
    void dfs(int sr, int sc, int originalColor, int newColor, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        if(sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != originalColor)
            return;

        image[sr][sc] = newColor;

        dfs(sr + 1, sc, originalColor, newColor, image);
        dfs(sr - 1, sc, originalColor, newColor, image);
        dfs(sr, sc + 1, originalColor, newColor, image);
        dfs(sr, sc - 1, originalColor, newColor, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor != color) 
            dfs(sr, sc, originalColor, color, image);
        return image;
    }
};
