class Solution {
public:
    string ans = "";

    void generate(int index, int n, string &curr, unordered_set<string> &st) {
        if (index == n) {
            if (st.find(curr) == st.end()) {
                ans = curr;
            }
            return;
        }

        if (ans != "") {
            return;
        }

        curr.push_back('0');
        generate(index + 1, n, curr, st);
        curr.pop_back();

        if (ans != "") {
            return;
        }

        curr.push_back('1');
        generate(index + 1, n, curr, st);
        curr.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        string curr = "";
        generate(0, n, curr, st);

        return ans;
    }
};