class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> answer;
        int i = 0;
        int n = s.length();

        while (i < n) {
            string ans = "";

            while (i < n && s[i] == ' ') i++;
            
            while (i < n && s[i] != ' ') {
                ans = ans + s[i];
                i++;
            }

            if (ans != "") {
                answer.push_back(ans);
            }
        }

     
        reverse(answer.begin(), answer.end());

        string final_ans = "";

        for (int i = 0; i < answer.size(); i++) {
            final_ans += answer[i];
            if (i != answer.size() - 1) {
                final_ans += " ";
            }
        }

        return final_ans;
    }
};
