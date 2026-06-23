class TrieNode{
public:

    TrieNode* child[26];

    // Stores at most 3 lexicographically smallest words
    vector<string> suggestions;

    TrieNode(){

        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

class Solution {
public:

    // Insert one word into Trie
    void insert(string word, TrieNode* root){

        TrieNode* curr = root;

        for(char ch : word){

            int ind = ch - 'a';

            if(curr->child[ind] == NULL){
                curr->child[ind] = new TrieNode();
            }

            curr = curr->child[ind];

            // Since products are inserted in sorted order,
            // first 3 words reaching this node are the answer.
            if(curr->suggestions.size() < 3){
                curr->suggestions.push_back(word);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        TrieNode* root = new TrieNode();

        // Important step
        sort(products.begin(), products.end());

        // Build Trie
        for(string &word : products){
            insert(word, root);
        }

        vector<vector<string>> ans;

        TrieNode* curr = root;

        for(char ch : searchWord){

            int ind = ch - 'a';

            // Prefix no longer exists
            if(curr == NULL || curr->child[ind] == NULL){

                curr = NULL;

                ans.push_back({});
            }
            else{

                curr = curr->child[ind];

                ans.push_back(curr->suggestions);
            }
        }

        return ans;
    }
};