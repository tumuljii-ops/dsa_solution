class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr,int sc,int start,vector<vector<int>>&visited,int color){
         
         int m=image.size();
         int n=image[0].size();

         if(sr>=m || sc>=n ||sc<0 ||sr<0||visited[sr][sc]||image[sr][sc]!=start) return ;

         image[sr][sc]=color;
         visited[sr][sc]=true;

         dfs(image,sr+1,sc,start,visited,color);
         dfs(image,sr-1,sc,start,visited,color);
         dfs(image,sr,sc+1,start,visited,color);
         dfs(image,sr,sc-1,start,visited,color);


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
           
             int row=image.size();
             int col=image[0].size();

             int start=image[sr][sc];

             if(start==color) return image;
             vector<vector<int>>visited(row,vector<int>(col,false));

             dfs(image,sr,sc,start,visited,color);

             return image;

    }
};
