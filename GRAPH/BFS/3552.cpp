class Solution {
public:
    int minMoves(vector<string>& matrix) {
            
            int n=matrix.size();
            int m=matrix[0].size();

            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

            deque<pair<int,pair<int,int>>>q;

            unordered_map<char,vector<pair<int,int>>>mpp;

            for(int i=0;i<n;i++){
                 
                 for(int j=0;j<m;j++){
                     
                      if(matrix[i][j]=='.'){
                        continue;
                      }
                      else if(matrix[i][j]=='#'){
                          continue;
                      }
                      else{
                          
                          char ch=matrix[i][j];
                          mpp[ch].push_back({i,j});
                      }
                 }
            }

            q.push_back({0,{0,0}});
            dist[0][0] = 0;

            vector<int>freq(256,0);

            while(!q.empty()){
                 
                 auto top=q.front();
                 q.pop_front();

                 int row=top.second.first;
                 int col=top.second.second;
                 int d=top.first;

                 if (d > dist[row][col]) continue;

                 if(row==n-1 && col==m-1){
                     return d;
                 }

                 if(isupper(matrix[row][col])){
                     char ch = matrix[row][col];
                     if(freq[ch] == 0){
                         freq[ch] = 1;
                         for(auto it: mpp[ch]){
                             int roww = it.first;
                             int coll = it.second;
                             if(d < dist[roww][coll]){
                                 dist[roww][coll] = d;
                                 q.push_front({d, {roww, coll}});
                             }
                         }
                     }
                 }

                 if(row+1<n && matrix[row+1][col]!='#' && d + 1 < dist[row+1][col]){
                      dist[row+1][col] = d + 1;
                      q.push_back({d+1,{row+1,col}});
                 }

                 if(row-1>=0 && matrix[row-1][col]!='#' && d + 1 < dist[row-1][col]){
                      dist[row-1][col] = d + 1;
                      q.push_back({d+1,{row-1,col}});
                 }

                 if(col-1>=0 && matrix[row][col-1]!='#' && d + 1 < dist[row][col-1]){
                      dist[row][col-1] = d + 1;
                      q.push_back({d+1,{row,col-1}});
                 }

                 if(col+1<m && matrix[row][col+1]!='#' && d + 1 < dist[row][col+1]){
                      dist[row][col+1] = d + 1;
                      q.push_back({d+1,{row,col+1}});
                 }
            }

            return -1;
    }
};