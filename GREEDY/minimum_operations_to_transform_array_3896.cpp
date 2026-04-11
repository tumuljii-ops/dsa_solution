class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = 100000 + 5;

        vector<bool>isprime(n, true);
        isprime[0] = false;
        isprime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isprime[i]) {
                for (int j = i * i; j < n; j = j + i) {
                    isprime[j] = false;
                }
            }
        }
        vector<int>nextprime(n);
        vector<int>next_non_prime(n);
        int last=-1;

        for(int i=n-1;i>=0;i--){
            if(isprime[i]) last=i;
            nextprime[i]=last;
            
        }

        last=-1;
        for(int i=n-1;i>=0;i--){
            if(!isprime[i]) last=i;
            next_non_prime[i]=last;
            
        }

        int ops=0;

        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ops=ops+nextprime[nums[i]]-nums[i];
            }
            else{
                ops+=next_non_prime[nums[i]]-nums[i];
            }
        }

        return ops;
    
    }
};