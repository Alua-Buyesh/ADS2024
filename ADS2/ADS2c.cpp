#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }

    void deleteEverySecond() {
        Node* current = head;
        Node* prev = nullptr;
        int count = 1;

        while (current) {
            if (count % 2 == 0) { // If count is even, we delete this node
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next; // Update head if the first node is deleted
                }
                Node* temp = current;
                current = current->next;
                delete temp; // Free the memory
            } else {
                prev = current;
                current = current->next;
            }
            count++;
        }
    }

    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;
    LinkedList ll;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        ll.append(val);
    }

    ll.deleteEverySecond();
    ll.printList();

    return 0;
}
