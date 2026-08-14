class Solution {
public:
    string toHex(int num) {
         
           if(num==0){
              return "0";
           }

           long long n=num;

           if(n<0){
              n=(1LL<<32)+n; // 2's compliment
           }

           string ans;

           while(n>0){
               
               int rem=n%16;

               if(rem<10){
                     int aa=rem;
                   ans+=(aa+'0');
               }
               else if(rem==10){
                   ans+='a';
               }
               else if(rem==11){
                    ans+='b';
               }
               else if(rem==12){
                    ans+='c';
               }
               else if(rem==13){
                   ans+='d';
               }
               else if(rem==14){
                    ans+='e';
               }
               else {
                ans+='f';
               }

               n=n/16;
           }

           reverse(ans.begin(),ans.end());

           return ans;
    }
};