class TrieNode{

    public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode(){

    for(int i=0;i<26;i++){
        child[i]=nullptr;

    }
     isEnd=false;
    }


};


class Trie {
public:

    TrieNode* root;
    Trie() {
        
        root =new TrieNode();
    }
    
    void insert(string word) {
         
          TrieNode* curr=root;

          for(char ch:word){
               int ind=ch-'a';

               if(curr->child[ind]==nullptr){
                   curr->child[ind]=new TrieNode();
               }

               curr=curr->child[ind];
          }

          curr->isEnd=true;
    }
    
    bool search(string word) {
          
            TrieNode* curr=root;

            for(char ch:word){
                 
                  int ind=ch-'a';

                  if(curr->child[ind]==nullptr){
                         return false;
                  }

                  curr=curr->child[ind];
            }

            return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
         
           TrieNode* curr=root;

           for(char ch:prefix){
                int ind=ch-'a';

                if(curr->child[ind]==nullptr){
                    return false;
                }

                curr=curr->child[ind];
           }

           return true;
    }
};