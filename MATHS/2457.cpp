class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long a = n;
        string s = to_string(a);

        // 1. Calculate initial digit sum
        long long initial_sum = 0;
        for (int i = 0; i < s.length(); i++) {
            initial_sum += (s[i] - '0');
        }
        if (initial_sum <= target) return 0;

        // 2. Find index 'ind' where running sum first reaches or exceeds target
        long long sum = 0;
        long long ind = 0;

        for (int i = 0; i < s.length(); i++) {
            sum = sum + (s[i] - '0');
            if (sum >= target) {
                ind = i;
                break;
            }
        }

        // 3. Build zeroes string 'ss' for remaining length
        long long len = s.length() - ind;
        string ss = "";
        for (int i = 0; i < len; i++) {
            ss += "0";
        }

        // 4. Increment the prefix before 'ind'
        string sss = "";
        if (ind >= 1) {
            string prefix = s.substr(0, ind);
            long long num = stoll(prefix);
            num = num + 1;
            sss = to_string(num);
        } else {
            sss = "1"; // If ind == 0, prefix round-up becomes 100...
        }

        // 5. Combine and calculate result
        string f = sss + ss;
        long long number = stoll(f);

        return number - n;
    }
};