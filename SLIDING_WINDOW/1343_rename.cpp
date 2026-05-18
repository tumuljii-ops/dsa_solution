class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
              
              int l=0;
              int r=0;

              int count=0;
              int n=arr.size();
              int sum=0;

              while(r<n){
                 sum+=arr[r];

                 while((r-l+1)>k){
                       sum=sum-arr[l];
                       l++;
                 }

                 if((r-l+1)==k && sum/3>=threshold){
                    count++;
                 }

                 r++;

              }

              return count;
    }
};