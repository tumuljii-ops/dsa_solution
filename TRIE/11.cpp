#include <bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
        long long a,b;
        cin>>a>>b;

        long long x_k,y_k;
        cin>>x_k>>y_k;

        long long x_q,y_q;
        cin>>x_q>>y_q;

        set<pair<long long,long long>>king_moves;

        long long dx[]={a,a,-a,-a,b,-b,b,-b};
        long long dy[]={b,-b,b,-b,a,a,-a,-a};

        for(int i=0;i<8;i++){
             
             king_moves.insert({dx[i]+x_k,dy[i]+y_k});
        }

        int count=0;

        for(auto it:king_moves){
             
              long long x=it.first;
              long long y=it.second;

              long long diff_x=abs(x-x_q);
              long long diff_y=abs(y-y_q);

              if((diff_x==a && diff_y==b)||(diff_x==b && diff_y==a)){
                   count++;
              }
        }

        cout<<count<<'\n';

       }

     return 0;
}