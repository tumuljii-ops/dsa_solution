class Solution {
public:
    bool checkPowersOfThree(int n) {

        int target = 0;
        int value = n;

        unordered_set<int> used;

        while(value > 0) {

            int number = 1;

            while(number * 3 <= value) {
                number *= 3;
            }

            if(used.count(number))
                return false;

            used.insert(number);

            target += number;
            value -= number;
        }

        return target == n;
    }
};