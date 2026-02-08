class Solution {
public:
    bool isPalindrome(int x) {
      
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int s = 0;
        int original = x;  

        
        while (x > s) {
            int r = x % 10;  
            s = s * 10 + r;  
            x /= 10;  
        }


        return x == s || x == s / 10;
    }
};