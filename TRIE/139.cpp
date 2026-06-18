class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {

        for(int i=0;i<26;i++) {
            child[i]=nullptr;
        }

        isEnd=false;
    }
};

class Solution {
public:

    TrieNode* root;

    void insert(string word) {

        TrieNode* curr=root;

        for(char ch:word) {

            int idx=ch-'a';

            if(curr->child[idx]==nullptr) {
                curr->child[idx]=new TrieNode();
            }

            curr=curr->child[idx];
        }

        curr->isEnd=true;
    }

    vector<int> dp;

    bool solve(int start,string &s) {

        int n=s.size();

        if(start==n) {
            return true;
        }

        if(dp[start]!=-1) {
            return dp[start];
        }

        TrieNode* curr=root;

        for(int i=start;i<n;i++) {

            int idx=s[i]-'a';

            if(curr->child[idx]==nullptr) {
                break;
            }

            curr=curr->child[idx];

            if(curr->isEnd) {

                if(solve(i+1,s)) {
                    return dp[start]=true;
                }
            }
        }

        return dp[start]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        root=new TrieNode();

        for(string word:wordDict) {
            insert(word);
        }

        dp.assign(s.size(),-1);

        return solve(0,s);
    }
};