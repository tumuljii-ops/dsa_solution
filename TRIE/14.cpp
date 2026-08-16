#include <bits/stdc++.h>
using namespace std;

int main(){
     
      int t;
      cin>>t;

      while(t--){
         int n;
         cin>>n;

         vector<long long>a(n);
         vector<long long>b(n);
         vector<long long>c(n);

         for(int i=0;i<n;i++){
               cin>>a[i];
               cin>>b[i];
               cin>>c[i];
         }

         priority_queue<pair<long long ,long long>>a1;
         priority_queue<pair<long long,long long>>b1;
         priority_queue<pair<long long,long long>>c1;

         for(int i=0;i<n;i++){
              a1.push({a[i],i});
              b1.push({b[i],i});
              c1.push({c[i],i});

         }

         while(!a1.empty() && )


      }
}