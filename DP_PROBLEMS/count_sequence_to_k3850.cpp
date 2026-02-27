class Solution {
public:
    
    int n;
    long long target;

    map<pair<int, pair<long long,long long>>, long long> memo;
    
    long long gcd(long long a, long long b){
        return b==0 ? a : gcd(b, a%b);
    }
    
    long long solve(int i, long long num, long long den, vector<int>& nums){

        long long g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
        
        if(i == n){
            if(num == target && den == 1) return 1;
            return 0;
        }
        
        auto key = make_pair(i, make_pair(num, den));
        if(memo.count(key)) return memo[key];
        
        long long ways = 0;
        
        ways += solve(i+1, num * nums[i], den, nums);
  
        ways += solve(i+1, num, den * nums[i], nums);
        
        ways += solve(i+1, num, den, nums);
        
        return memo[key] = ways;
    }
    
    int countSequences(vector<int>& nums, long long k) {
        n = nums.size();
        target = k;
        memo.clear();
        
        return solve(0, 1, 1, nums);
    }
};