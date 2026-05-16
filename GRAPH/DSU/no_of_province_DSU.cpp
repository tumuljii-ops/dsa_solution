class Solution {
public:
    class DISJOINT{

        public:
        
         vector<int>parent;
         vector<int>rank;

         DISJOINT(int n){
             parent.resize(n);
             rank.resize(n,1);

             for(int i=0;i<n;i++){
                parent[i]=i;
             }
         }

         void Union(int a,int b){
               
               int parent_a=find(a);
               int parent_b=find(b);

               if(parent_a==parent_b){
                     return ;
               }

               if(rank[parent_a]==rank[parent_b]){
                   rank[parent_a]++;
                   parent[parent_b]=parent_a;
               }
               else if(rank[parent_a]<rank[parent_b]){
                    parent[parent_a]=parent_b;
               }
               else{
                  parent[parent_b]=parent_a;
               }
         }

         int find(int x){
             
              if(parent[x]==x){
                  return x;
              }

              return parent[x]=find(parent[x]);
         }

    };
    int findCircleNum(vector<vector<int>>& isConnected) {
             
             int n=isConnected.size();

             DISJOINT ds(n);

             for(int i=0;i<n;i++){
                 for(int j=0;j<n;j++){
                      if(isConnected[i][j]==1){
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

             return count;


    }
};