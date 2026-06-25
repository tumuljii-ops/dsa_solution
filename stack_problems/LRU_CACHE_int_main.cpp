#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;

    Node *head, *tail;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

public:
    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->value = value;

            deleteNode(node);
            addNode(node);

            return;
        }

        if(mp.size() == capacity) {

            Node* lru = tail->prev;

            deleteNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key, value);

        addNode(newNode);
        mp[key] = newNode;
    }

    void display() {

        Node* temp = head->next;

        while(temp != tail) {
            cout << "(" << temp->key << "," << temp->value << ") ";
            temp = temp->next;
        }

        cout << "\n";
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cache.display();

    cout << "Get 1 = " << cache.get(1) << "\n";

    cache.put(3, 30);

    cache.display();

    cout << "Get 2 = " << cache.get(2) << "\n";

    cache.put(4, 40);

    cache.display();

    cout << "Get 1 = " << cache.get(1) << "\n";
    cout << "Get 3 = " << cache.get(3) << "\n";
    cout << "Get 4 = " << cache.get(4) << "\n";

    return 0;
}