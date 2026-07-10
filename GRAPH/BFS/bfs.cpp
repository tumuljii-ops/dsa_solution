#include <bits/stdc++.h>
using namespace std;

void add(int u,int v,vector<vector<int>>&adj){
      adj[u].push_back(v);
      adj[v].push_back(u);
}

void bfs(int node,vector<vector<int>>&adj,vector<int>&visited){
    queue<int>q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int node=q.front();
        cout<<node<<" ";
        q.pop();

        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=true;
                q.push(it);
            }
        }
    }

}

int main(){
    int n;
    cout<<"enter the number of vertex:";
    cin>>n;

    vector<int>visited(n,false);
    vector<vector<int>>adj(n);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        add(u,v,adj);
    }

    int start;
    cout<<"enter the starting node of the graph:";
    cin>>start;

    cout<<"bfs traversal is as follow:";
    bfs(start,adj,visited);





}