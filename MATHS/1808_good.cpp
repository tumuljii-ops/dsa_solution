class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int maxNiceDivisors(int primeFactors) {

        if (primeFactors <= 3)
            return primeFactors;

        if (primeFactors % 3 == 0) {
            return power(3, primeFactors / 3);
        }
        else if (primeFactors % 3 == 1) {
            return (power(3, (primeFactors - 4) / 3) * 4) % MOD;
        }
        else {
            return (power(3, (primeFactors - 2) / 3) * 2) % MOD;
        }
    }
};