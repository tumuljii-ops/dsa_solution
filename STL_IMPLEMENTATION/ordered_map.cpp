#include <iostream>
using namespace std;

class Node {

public:
    int key;
    int value;

    Node* left;
    Node* right;

    Node(int k,int v) {
        key = k;
        value = v;

        left = NULL;
        right = NULL;
    }
};

class OrderedMap {

private:

    Node* root;

    Node* insert(Node* node,
                 int key,
                 int value) {

        if(node == NULL)
            return new Node(key,value);

        if(key < node->key) {
            node->left =
                insert(node->left,key,value);
        }

        else if(key > node->key) {
            node->right =
                insert(node->right,key,value);
        }

        else {
            node->value = value;
        }

        return node;
    }

    Node* search(Node* node,int key) {

        if(node == NULL)
            return NULL;

        if(node->key == key)
            return node;

        if(key < node->key)
            return search(node->left,key);

        return search(node->right,key);
    }

    void inorder(Node* node) {

        if(node == NULL)
            return;

        inorder(node->left);

        cout << node->key
             << " -> "
             << node->value
             << endl;

        inorder(node->right);
    }

public:

    OrderedMap() {
        root = NULL;
    }

    void put(int key,int value) {
        root = insert(root,key,value);
    }

    int get(int key) {

        Node* res =
            search(root,key);

        if(res)
            return res->value;

        return -1;
    }

    void display() {
        inorder(root);
    }
};

int main() {

    OrderedMap mp;

    mp.put(10,100);
    mp.put(5,50);
    mp.put(20,200);
    mp.put(15,150);
    mp.put(7,70);

    cout << "Key 20 = "
         << mp.get(20)
         << endl;

    cout << "\nOrdered Map:\n";

    mp.display();
}