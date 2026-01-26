class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string s) {
        url = s;
        prev = next = nullptr;
    }
};

class BrowserHistory {
public:
    Node* current;

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        // Clear forward history
        if (current->next) {
            current->next->prev = nullptr;
            current->next = nullptr;
        }

        // Create new page
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps) {
        while (steps > 0 && current->prev) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while (steps > 0 && current->next) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};
