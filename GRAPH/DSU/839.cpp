class DSU{
     private:
     vector<int>parent;
     vector<int>rank;

     public:
     DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
     }

     int find_Parent(int x){
         
           if(parent[x]==x){
               return x;
           }

           return parent[x]=find_Parent(parent[x]);
     }

     void Union(int a,int b){
         
           int a_parent=find_Parent(a);
           int b_parent=find_Parent(b);

           if(rank[a_parent]<rank[b_parent]){
                parent[a_parent]=b_parent;
           }
           else if(rank[b_parent]<rank[a_parent]){
                 parent[b_parent]=a_parent;
           }
           else{
              parent[a_parent]=b_parent;
              rank[b_parent]++;
           }
     }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {

         int a=strs.size();
         
         DSU dsu(a);

         for(int i=0;i<strs.size();i++){

               string answer=strs[i];

              for(int j=i+1;j<strs.size();j++){
                     string answer1=strs[j];

                     int k=0;
                     int count=0;

                     while(k<answer.length()){
                          
                           if(answer[k]!=answer1[k]){
                                 count++;
                           }
                           k++;
                     }

                     if(count==0||count==2){
                     dsu.Union(i,j);
                     }
                       
              }

         }

         int total=0;

         for(int i=0;i<a;i++){
             if(dsu.find_Parent(i)==i){
                total++;
             }               
 
         }

         return total;


    }
};