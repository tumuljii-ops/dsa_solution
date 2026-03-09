class Solution {
public:
    int mod = 1e9 + 7;

    int dp[201][201][2];

    int solve(int z, int o, int last, int limit){

        if(z == 0 && o == 0){
            return 1;
        }

        if(dp[z][o][last] != -1){
            return dp[z][o][last];
        }

        long long ans = 0;

        if(last == 0){
            for(int k = 1; k <= limit && k <= o; k++){
                ans += solve(z, o - k, 1, limit);
                ans %= mod;
            }
        }
        else{
            for(int k = 1; k <= limit && k <= z; k++){
                ans += solve(z - k, o, 0, limit);
                ans %= mod;
            }
        }

        return dp[z][o][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        for(int k = 1; k <= limit && k <= zero; k++){
            ans += solve(zero - k, one, 0, limit);
            ans %= mod;
        }

        for(int k = 1; k <= limit && k <= one; k++){
            ans += solve(zero, one - k, 1, limit);
            ans %= mod;
        }

        return ans;
    }
};