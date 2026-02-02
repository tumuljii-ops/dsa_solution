class LFUCache {
public:
 
    struct Node {
        int key, value, freq;
        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };
    
    int capacity;
    int minFreq;
    
    unordered_map<int, Node*> keyNode;          
    unordered_map<int, list<Node*>> freqList;   
    unordered_map<Node*, list<Node*>::iterator> nodePos;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;
        
        Node* node = keyNode[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (keyNode.size() == capacity) {
              
                Node* nodeToRemove = freqList[minFreq].back();
                keyNode.erase(nodeToRemove->key);
                nodePos.erase(nodeToRemove);
                freqList[minFreq].pop_back();
                delete nodeToRemove;
            }
            
            Node* newNode = new Node(key, value);
            keyNode[key] = newNode;
            freqList[1].push_front(newNode);
            nodePos[newNode] = freqList[1].begin();
            minFreq = 1;
        }
    }
    
private:
    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqList[oldFreq].erase(nodePos[node]);
        
   
        if (freqList[oldFreq].empty() && minFreq == oldFreq)
            minFreq++;
        
        node->freq++;
        freqList[node->freq].push_front(node);
        nodePos[node] = freqList[node->freq].begin();
    }
};