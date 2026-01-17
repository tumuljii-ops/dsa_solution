class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int source){
        visited[source]=true;
        
        for(auto it:adj[source]){
            if(!visited[it]){
                dfs(adj,visited,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n=isConnected.size();
         int m=isConnected[0].size();

         vector<int>visited(n,false);
         vector<vector<int>>adj(n);

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
         }

        int count=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,visited,i);
            }
        }
        return count;
    }
};