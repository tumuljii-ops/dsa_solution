#include <bits/stdc++.h>
using namespace std;

int main(){
     
     int t;
     cin>>t;

     while(t--){
         
         int n;
         cin>>n;

         string s;
         cin>>s;

         vector<int>visited(26,0);

         visited[s[0]-'A']=1;

         bool ans=false;

         for(int i=1;i<s.length();i++){
               if((s[i]==s[i-1]) && (visited[s[i]-'A']==1)){
                    continue;
               }
               else if(visited[s[i]-'A']==1){
                    ans=true;
                    break;
               }
               else if(visited[s[i]-'A']==0){
                    visited[s[i]-'A']=1;
               }
         }

         if(ans){
            cout<<"NO"<<'\n';
         }
         else{
            cout<<"YES"<<'\n';
         }

        
     }

     return 0;
}