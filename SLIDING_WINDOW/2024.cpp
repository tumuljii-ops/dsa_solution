class Solution {
public:

    int solve(string &s, int k, char ch){

        int l = 0;
        int r = 0;
        int count = 0;
        int ans = 0;

        while(r < s.size()){

            if(s[r] != ch){
                count++;
            }

            while(count > k){

                if(s[l] != ch){
                    count--;
                }

                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(
            solve(answerKey, k, 'T'),
            solve(answerKey, k, 'F')
        );
    }
};