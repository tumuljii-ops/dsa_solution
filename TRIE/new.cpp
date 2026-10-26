#include <bits/stdc++.h>
using namespace std;

int main(){
      int t;
     
      cin>>t;

      while(t--){
           
           int n;
           cin>>n;

           vector<long long>arr(n);

           for(int i=0;i<n;i++){
                cin>>arr[i];
           }

           long long mini=LLONG_MAX;

           for(int i=0;i<n;i++){
                mini=min(mini,arr[i]);
           }

           for(int i=0;i<n;i++){
                if(arr[i]==0){
                     cout<<n<<'\n';
                     continue;
                }
           }

           if(mini<n){
               cout<<n<<'\n';
           }


      }

      return 0;

}