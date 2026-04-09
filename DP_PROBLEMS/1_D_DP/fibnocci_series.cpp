class Solution {
public:
    int fibb(int num,vector<int>&dpp){
         
         if(num<=1) return num;

         if(dpp[num]!=-1) return dpp[num];

         dpp[num]=fibb(num-1,dpp)+fibb(num-2,dpp);

         return dpp[num];
    }
    int fib(int n) {
          vector<int>dp(n+1,-1);

          int fib_number=fibb(n,dp);

          return fib_number;
    }
};

//-----------tabulation--------------
  int fib(int n) {
         if(n<=1) return n;

         vector<int>tab(n+1,-1);

          tab[0]=0;
          tab[1]=1;

         for(int i=2;i<=n;i++){
            tab[i]=tab[i-1]+tab[i-2];
         }

          return tab[n];
    }
};