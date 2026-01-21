#include <bits/stdc++.h>
using namespace std;

class Node {
public: // Make members public for easy access
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Add a node with 'data' at position 'k' (1-based index)
Node* add(Node* head, int data, int k) {
    Node* newNode = new Node(data);

    if (k == 1) { // Insert at head
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        delete newNode;
        return head;
    }

    newNode->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete a node at position 'k' (1-based index)
Node* deleteNode(Node* head, int k) {
    if (head == nullptr) return nullptr;

    Node* temp = head;

    if (k == 1) { // Delete head
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        return head;
    }

    for (int i = 1; i < k && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return head;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
    return head;
}

// Print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;

    head = add(head, 10, 1); // Add 10 at position 1
    head = add(head, 20, 2); // Add 20 at position 2
    head = add(head, 30, 3); // Add 30 at position 3
    head = add(head, 15, 2); // Add 15 at position 2

    cout << "List after additions: ";
    printList(head); // Should print: 10 15 20 30

    head = deleteNode(head, 3); // Delete node at position 3 (20)
    cout << "List after deletion: ";
    printList(head); // Should print: 10 15 30

    return 0;
}
