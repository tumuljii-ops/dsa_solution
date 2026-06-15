#include <iostream>

using namespace std;

class Node {

public:

    int key;

    Node* left;
    Node* right;

    Node(int k) {

        key = k;

        left = NULL;
        right = NULL;
    }
};

class OrderedSet {

private:

    Node* root;

    Node* insertNode(Node* node,int key) {

        if(node == NULL)
            return new Node(key);

        if(key < node->key) {
            node->left =
                insertNode(node->left,key);
        }

        else if(key > node->key) {
            node->right =
                insertNode(node->right,key);
        }

        return node;
    }

    bool search(Node* node,int key) {

        if(node == NULL)
            return false;

        if(node->key == key)
            return true;

        if(key < node->key)
            return search(node->left,key);

        return search(node->right,key);
    }

    void inorder(Node* node) {

        if(node == NULL)
            return;

        inorder(node->left);

        cout << node->key << " ";

        inorder(node->right);
    }

public:

    OrderedSet() {
        root = NULL;
    }

    void insert(int key) {
        root = insertNode(root,key);
    }

    bool find(int key) {
        return search(root,key);
    }

    void display() {

        inorder(root);

        cout << endl;
    }
};

int main() {

    OrderedSet st;

    st.insert(10);
    st.insert(5);
    st.insert(20);
    st.insert(7);
    st.insert(15);

    st.display();

    cout << st.find(15) << endl;
    cout << st.find(100) << endl;
}