class LRUCache {
public:
    class Node{

        public:

        Node* next;
        Node* prev;
        int key;
        int val;

        Node(int k,int v){
             key=k;
             val=v;
             next=prev=NULL;
        }

    };

    int limit;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mpp;

    LRUCache(int capacity) {
          limit=capacity;
          head=new Node(-1,-1);
          tail=new Node(-1,-1);
          head->next=tail;
          tail->prev=head;

    }

    void add(Node* node){
         
          Node* next_node=head->next;

          head->next=node;
          next_node->prev=node;

          node->next=next_node;
          node->prev=head;
    }

    void del(Node* node){
         
          node->next->prev=node->prev;
          node->prev->next=node->next;

          node->next=nullptr;
          node->prev=nullptr;
    }
    
    int get(int key) {
          
           if(mpp.find(key)==mpp.end()){
               
               return -1;
           }

           Node* node=mpp[key];

           del(node);
           add(node);

           return node->val;

    }
    
    void put(int key, int value) {
          
           if(mpp.find(key)!=mpp.end()){
               
                Node* node=mpp[key];
                node->val=value;

                del(node);
                add(node);
           }
           else{
             
                if(mpp.size()==limit){
                     
                      Node* lru=tail->prev;

                      mpp.erase(lru->key);
                      del(lru);
                     // delete(lru);
                }

                Node* node=new Node(key,value);

                mpp[key]=node;
                add(node);

           }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
