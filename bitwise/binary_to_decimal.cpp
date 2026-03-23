class Solution {
public:
    int binaryToDecimal(string &b) {
        int sum = 0;

        for(int i = 0; i < b.length(); i++){
            sum = sum * 2 + (b[i] - '0');
        }

        return sum;
    }
};