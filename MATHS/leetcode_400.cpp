class Solution {
public:
    int findNthDigit(int n) {
         
         long long count=9;
         long long len=1;
         long long start=1;

         while(n>count*len){
              n=n-count*len;
              count=count*10;
              len++;
              start=start*10;
         }

         long long target_number=start+(n-1)/len;

         string ans=to_string(target_number);

         return ans[(n-1)%len]-'0';

        
    }
};