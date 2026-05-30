class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;

        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        k = k - 1;
        string ans = "";

        while (true) {
            int index = k / fact;
            ans = ans + to_string(numbers[index]);

            vector<int> anss;
            for (int i = 0; i < numbers.size(); i++) {
                if (i == index) {
                    continue;
                }
                anss.push_back(numbers[i]);
            }

            numbers = anss;

            if (numbers.size() == 0) {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
        }

        return ans;
    }
};