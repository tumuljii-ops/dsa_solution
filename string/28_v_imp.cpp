class Solution {
public:

    vector<int> lps(string answer){

        int len = 0;
        int i = 1;
        int n = answer.size();

        vector<int> lps(n,0);

        while(i < n){

            if(answer[i] == answer[len]){
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

    int strStr(string haystack, string needle) {

        if(needle.size() == 0)
            return 0;

        vector<int> prefix = lps(needle);

        int n1 = haystack.size();
        int n2 = needle.size();

        int i = 0;
        int j = 0;

        while(i < n1){

            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if(j == n2){
                return i - j;
            }

            else if(i < n1 && haystack[i] != needle[j]){

                if(j != 0){
                    j = prefix[j-1];
                }
                else{
                    i++;
                }
            }
        }

        return -1;
    }
};