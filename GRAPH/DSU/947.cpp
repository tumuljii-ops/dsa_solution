class Solution {
public:
    class DSU{
        
        vector<int>parent;
        vector<int>rank;

        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);

            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int find(int x){
             if(parent[x]==x){
                return x;
             }

             return parent[x]=find(parent[x]);
        }

        void Union(int a,int b){
             int parent_a=find(a);
             int parent_b=find(b);

             if(parent_a==parent_b) return;

             if(rank[parent_a]<rank[parent_b]){
                  parent[parent_a]=parent_b;
                  rank[parent_b]++;
             }
             else if(rank[parent_b]<rank[parent_a]){
                 parent[parent_b]=parent_a;
                 rank[parent_a]++;
             }
             else{
                parent[parent_b]=parent_a;
                rank[parent_a]++;

             }
        }
    };
    int removeStones(vector<vector<int>>& stones) {
           
           int n=stones.size();

           DSU ds(n);

           for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 
                  if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                     ds.Union(i,j);
                  }
            }
           }

           int count=0;

           for(int i=0;i<n;i++){
               if(ds.parent[i]==i){
                count++;
               }
           }


           return n-count;
    }
};