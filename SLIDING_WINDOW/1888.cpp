class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();

        string ss = s + s;
        string alt1 = "";
        string alt2 = "";

        for(int i = 0; i < 2 * n; i++) {

            if(i % 2 == 0)
                alt1 += '0';
            else
                alt1 += '1';

            if(i % 2 == 0)
                alt2 += '1';
            else
                alt2 += '0';
        }

        int left = 0;

        int diff1 = 0;

        int diff2 = 0;

        int ans = INT_MAX;

        for(int right = 0; right < 2 * n; right++) {

            if(ss[right] != alt1[right])
                diff1++;

            if(ss[right] != alt2[right])
                diff2++;

            if(right - left + 1 > n) {

                if(ss[left] != alt1[left])
                    diff1--;

                if(ss[left] != alt2[left])
                    diff2--;

                left++;
            }

            if(right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};