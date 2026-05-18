class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countof5 = 0, countof10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                countof5++;
            } 
            else if (bill == 10) {
                if (countof5 == 0) return false; 
                countof5--;
                countof10++;
            } 
            else { 
                if (countof10 > 0 && countof5 > 0) {
                    countof10--;
                    countof5--;
                } else if (countof5 >= 3) {
                    countof5 -= 3;
                } else {
                    return false; 
                }
            }
        }
        
        return true; 
    }
};
