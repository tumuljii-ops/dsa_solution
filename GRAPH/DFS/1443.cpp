class Solution {
public:
    
    int dfs(unordered_map<int,vector<int>>&adj,vector<bool>&hasApple,int parent,int child){
            
            int time=0;
            for(auto curr:adj[child]){
                  
                   if(curr==parent) continue;

                   int curr_time=dfs(adj,hasApple,child,curr);

                   if(curr_time>0 || hasApple[curr]){
                      
                        time=time+2+curr_time;
                   }
            }

            return time;        
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
            

                unordered_map<int,vector<int>>adj;

                for(int i=0;i<edges.size();i++){
                      
                      int u=edges[i][0];
                      int v=edges[i][1];

                      adj[u].push_back(v);
                      adj[v].push_back(u);
                }

                return dfs(adj,hasApple,-1,0);
    }
};