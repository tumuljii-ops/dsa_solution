#include <bits/stdc++.h>
using namespace std;

void add(vector<vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int>&visited,int start,vector<vector<int>>&adj){
    cout<<start<<" ";
    visited[start]=true;

    for(auto it: adj[start]){
        if(!visited[it]){
            dfs(visited,it5,adj);
        }
    }

}

int main(){
    int n;
    cout<<"enter the number of nodes:";
    cin>>n;

    vector<int>visited(n,false);
    vector<vector<int>>adj(n);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        add(adj,u,v);
    }
    
    
    cout<<"dfs traversal is :";
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(visited,i,adj);
        }
    }


}