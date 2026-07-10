#include <bits/stdc++.h>
using namespace std;

void add(int u,int v,vector<vector<int>>&adj){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int start,vector<vector<int>>&adj,vector<int>&visited){
      cout<<start<<'\n';
      visited[start]=true;

      for(auto it:adj[start]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
      }
}

int main(){
    int u;
    int v;
    int n=5;

    vector<vector<int>>adj(5);

    for(int i=0;i<n;i++){
        cin>>u;
        cin>>v;
       add(u,v,adj);
    }

    vector<int>visited(5,false);

    for(int i=0;i<5;i++){
        if(!visited[i]){
            dfs(i,adj,visited);
        }
    }
    return 0;

}