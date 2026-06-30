#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);  // dummy head
        tail = new Node(-1, -1);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        deleteNode(node);
        addNode(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            addNode(node);
        } else {
            if (mp.size() == cap) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
            }
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addNode(newNode);
        }
    }
};
