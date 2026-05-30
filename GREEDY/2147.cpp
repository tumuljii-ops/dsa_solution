class Solution {
public:
    int numberOfWays(string corridor) {

            const long long mod=1e9+7;
            
             vector<int>position;

             int n=corridor.length();

             for(int i=0;i<n;i++){
                 
                  if(corridor[i]=='S'){
                      position.push_back(i);
                  }
             }

             int n1=position.size();

             if(n1%2==1 || n1==0) return 0;

             long long ans=1;

             for(int i=2;i<n1;i+=2){
                  
                   ans=(ans*(position[i]-position[i-1]))%mod;
             }

             return ans;

    }
};