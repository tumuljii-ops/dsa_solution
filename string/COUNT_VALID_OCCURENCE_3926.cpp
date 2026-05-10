class Solution {
public:
    bool isLetter(char c){
         return c>='a' && c<='z';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        string s;

        for(auto &x:chunks){
             s+=x;
        }

        unordered_map<string,int>freq;

        int n=s.size();

        string cur="";

        for(int i=0;i<n;i++){

             char c=s[i];

            bool valid=false;

            if(isLetter(c)){
                valid=true;
            }

            else if(c=='-' && i>0 && i+1<n && isLetter(s[i-1]) && isLetter(s[i+1])){
                valid=true;
            }

            if(valid){
                cur+=c;
            }
            else{

                if(!cur.empty()){
                    freq[cur]++;
                    cur.clear();
                }
            }
        }

        if(!cur.empty()){
            freq[cur]++;
        }

        vector<int>ans;

        for(auto &q:queries){
             ans.push_back(freq[q]);
        }

        return ans;
    }
};