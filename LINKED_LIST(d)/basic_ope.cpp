#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int length(Node* head) {
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool search(Node* head, int element) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == element) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);

    print(head);

    cout << "Length of list: " << length(head) << endl;

    int x = 6;
    if (search(head, x))
        cout << x << " found in list\n";
    else
        cout << x << " not found in list\n";

    return 0;
}
