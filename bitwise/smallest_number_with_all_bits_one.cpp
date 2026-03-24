class Solution {
public:
    int smallestNumber(int n) {
        if(n==0) return 1;

        int num=floor(log2(n))+1;

        int pow=(1<<num);

        return pow-1;
    }
};