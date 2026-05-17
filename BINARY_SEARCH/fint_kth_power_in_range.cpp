class Solution {
public:
    long long power(long long a,int k,long long limit){
         if(a==0) return 0;
         long long ans=1;

         for(int i=0;i<k;i++){
              if(ans>limit/a){
                  return limit+1;
              }
             ans*=a;
         }

        return ans;
    }
    long long kthroot(long long n,int k){
         if(n<0) return 0;
         long long low=0;
         long long high=n;

         long long ans=0;

         while(low<=high){
             long long mid=(low+high)/2;

             if(power(mid,k,n)<=n){
                 ans=mid;
                 low=mid+1;
                // ans=mid;
             }
             else{
                 high=mid-1;
             }
         }

        return ans;
    }
    int countKthRoots(int l, int r, int k) {
        long long right=kthroot(r,k);
        long long left=(l==0)? 0 : kthroot((long long)l-1,k);

        return right-left+(l==0 ? 1:0);
    }
};