class Solution {
public:
    int waysToSplit(vector<int>& nums) {
                
                int n=nums.size();

                vector<int>prefixsum(n);
                prefixsum[0]=nums[0];

                for(int i=1;i<n;i++){
                     prefixsum[i]=prefixsum[i-1]+nums[i];
                }

                int j=1;
                int k=1;

                int count=0;
                int total=prefixsum[n-1];

                int mod=1e9+7;

                for(int i=0;i<n-2;i++){
                       
                       j = max(j, i + 1);
                        k = max(k, i + 1);
                      
                       //lower bound
                       while(j<n-1 && prefixsum[j]<2*prefixsum[i]){
                        j++;
                       }

                       //upper bound

                       while(k< n-1 && prefixsum[k]<=(total+prefixsum[i])/2){
                        k++;
                       }

                       if(j<=k-1){
                         count=(count+(k-j))%mod;
                       }
                }

                return count;
    }
};