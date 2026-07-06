class Solution {
public:

    vector<int> buildLPS(string &s){

        int n = s.size();

        vector<int> lps(n,0);

        int len = 0;
        int i = 1;

        while(i < n){

            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{

                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int minimumTimeToInitialState(string word, int k) {

        int n = word.size();

        vector<int> lps = buildLPS(word);

        vector<bool> border(n + 1, false);

        int len = lps[n-1];

        while(len > 0){
            border[len] = true;
            len = lps[len-1];
        }

        int time = 1;

        while(time * k < n){

            int remain = n - time * k;

            if(border[remain])
                return time;

            time++;
        }

        return time;
    }
};