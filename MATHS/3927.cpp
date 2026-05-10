class Solution {
public:
    long long minArraySum(vector<int>& nums) {

           const int MAX=100000;

           vector<bool>present(MAX+1,false);

           for(int x:nums){

                present[x]=true;
           }

               long long ans=0;

               for(int x:nums){
                   int best=x;

                   for(int d=1;d*d<=x;d++){

                       if(x%d==0){
                           if(present[d]){
                               best=min(best,d);
                           }

                           int other=x/d;

                           if(present[other]){
                               best=min(best,other);
                           }
                       }
                   }
                   ans+=best;
               }

               //ans+=best;
           

        return ans;
    }
};