class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
             
             unordered_map<int,int>mpp;

             vector<int>power;

             for(int i=0;i<=21;i++){
                  power.push_back(1<<i);
             }

             long long count=0;
             int mod=1e9+7;

             for(int x:deliciousness){
                  
                    for(int y:power){
                          
                          int target=y-x;

                          if(mpp.find(target)!=mpp.end()){
                            count=(count+mpp[target])%mod;
                          }
                    }

                    mpp[x]++;
             }

             return count;
            
    }
};