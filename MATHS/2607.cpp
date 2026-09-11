class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
          
             int n=arr.size();

             int g=gcd(n,k);

             long long total_ops=0;

             for(int i=0;i<g;i++){
                 
                   vector<int>group;

                   for(int j=i;j<n;j+=g){
                      
                         group.push_back(arr[j]);
                   }

                   sort(group.begin(),group.end());

                   int x=group.size();

                   long long median=group[x/2];

                   for(int num:group){
                        
                        total_ops=total_ops+abs(median-num);
                        
                   }
             }

             return total_ops;
    }
};