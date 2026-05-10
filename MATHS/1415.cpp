class Solution {
public:
    string getHappyString(int n, int k) {
        
        int total = 3 * (1 << (n - 1));

        if (k > total) {
            return "";
        }

        string ans = "";

        char prev = '#';

        for (int i = 0; i < n; i++) {

            vector<char> choices;

            for (char ch : {'a', 'b', 'c'}) {
                if (ch != prev) {
                    choices.push_back(ch);
                }
            }

            int remaining = n - i - 1;

            int blockSize = (1 << remaining);

            for (char ch : choices) {

                if (k > blockSize) {
                    k -= blockSize;
                }
                else {
                    ans.push_back(ch);
                    prev = ch;
                    break;
                }
            }
        }

        return ans;
    }
};