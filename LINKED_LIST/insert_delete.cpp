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

// Function to insert at position k
Node* insert_element(Node* head, int val, int k) {
    Node* newNode = new Node(val);

    if (k == 1) {
        newNode->next = head;
        return newNode; // new head
    }

    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        delete newNode;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete element at position k
Node* delete_element(Node* head, int k) {
    if (head == nullptr) return nullptr;

    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    int count = 1;

    while (temp->next != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr) {
        cout << "Position out of bounds\n";
        return head;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;

    return head;
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Print\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            int val, pos;
            cout << "Enter value and position to insert: ";
            cin >> val >> pos;
            head = insert_element(head, val, pos);
        } else if (choice == 2) {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            head = delete_element(head, pos);
        } else if (choice == 3) {
            print(head);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
