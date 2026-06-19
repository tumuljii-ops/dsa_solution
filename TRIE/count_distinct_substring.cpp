class TrieNode {
public:
    TrieNode* child[26];

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Solution {
public:

    void insert(string &word, TrieNode* root) {

        TrieNode* curr = root;

        for(char ch : word) {

            int ind = ch - 'a';

            if(curr->child[ind] == NULL) {
                curr->child[ind] = new TrieNode();
            }

            curr = curr->child[ind];
        }
    }

    int countNodes(TrieNode* root) {

        if(root == NULL) {
            return 0;
        }

        int cnt = 1;

        for(int i = 0; i < 26; i++) {
            cnt += countNodes(root->child[i]);
        }

        return cnt;
    }

    int countSubs(string& s) {

        TrieNode* root = new TrieNode();

        // Form all suffixes and insert them
        for(int i = 0; i < s.length(); i++) {

            string suffix = s.substr(i);

            insert(suffix, root);
        }

        // Exclude root node
        return countNodes(root) - 1;
    }
};