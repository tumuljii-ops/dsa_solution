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
Node* reverse_linkedlist(Node* head) {
    Node* temp = nullptr;
    Node* current = head;

    // Swap next and prev for all nodes
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // move to next node (which is old prev)
    }

    // After the loop, temp points to the old head's prev (new head)
    if (temp != nullptr) {
        head = temp->prev;
    }

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

    head = add(head, 10, 1); 
    head = add(head, 20, 2); 
    head = add(head, 30, 3); 
    head = add(head, 15, 2); 

    cout << "List after additions: ";
    printList(head); // 10 15 20 30

    head = reverse_linkedlist(head);
    cout << "List after reversing: ";
    printList(head); // 30 20 15 10

    return 0;
}
