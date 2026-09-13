class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        
        int top=0;
        int bottom=mat.size()-1;
        
        int left=0;
        int right=mat[0].size()-1;
        vector<int>ans;
        
        while(top<=bottom && left<=right){
              
              
              for(int i=left;i<=right;i++){
                   ans.push_back(mat[top][i]);
              }
              
              top++;
              
              for(int j=top;j<=bottom;j++){
                   ans.push_back(mat[j][right]);
              }
              
              right--;
              
              if(top<=bottom){
                   
                   for(int k=right;k>=left;k--){
                        ans.push_back(mat[bottom][k]);
                   }
                   
                   bottom--;
              }
              
              if(left<=right){
                  
                   
                   for(int l=bottom;l>=top;l--){
                        ans.push_back(mat[l][left]);
                   }
                   
                   left++;
              }
               
        }
        
        return ans;
        
    }
};