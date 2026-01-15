class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,long long>ans;

        for(auto word:words){
            string pattern;
            for(int i=0;i<word.length();i++){
                int diff=(word[i]-word[0]+26)%26;
                pattern += char(diff + 'a');
            }
            ans[pattern]++;
        }

        long long totalPairs = 0;
        for(auto &[pattern, count] : ans){
            totalPairs += count * (count - 1) / 2;
        }

        return totalPairs;
    }
};