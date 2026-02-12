class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || s.length() <= numRows)
            return s;

        vector<vector<char>> ans(numRows);

        int ind = 0;
        int d = 1;

        for(char c : s){
            ans[ind].push_back(c);

            if(ind == 0)
                d = 1;
            else if(ind == numRows - 1)
                d = -1;

            ind += d;
        }

        string result = "";

        for(int i = 0; i < ans.size(); i++){
            for(char c : ans[i]){
                result += c;
            }
        }

        return result;
    }
};
