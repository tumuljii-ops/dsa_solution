class Solution {
public:
    string largestMerge(string word1, string word2) {

        string merge = "";

        int i = 0;
        int j = 0;

        int n1 = word1.length();
        int n2 = word2.length();

        while(i < n1 && j < n2) {

            if(word1[i] > word2[j]) {

                merge += word1[i];
                i++;
            }

            else if(word1[i] < word2[j]) {

                merge += word2[j];
                j++;
            }

            else {

                if(word1.substr(i) > word2.substr(j)) {

                    merge += word1[i];
                    i++;
                }

                else {

                    merge += word2[j];
                    j++;
                }
            }
        }

        while(i < n1) {
            merge += word1[i];
            i++;
        }

        while(j < n2) {
            merge += word2[j];
            j++;
        }

        return merge;
    }
};