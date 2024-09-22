#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(string value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addToEnd(string value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rearrange(int index) {
        if (head == nullptr || index == 0) return;

        Node* temp = head;
        int count = 0;

        while (count < index && temp != nullptr) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) return;

        Node* newHead = temp;
        Node* newTail = temp->prev;

        if (newTail != nullptr) {
            newTail->next = nullptr;  
        }
        
        newHead->prev = nullptr;

        tail->next = head;
        head->prev = tail;

        head = newHead;
        tail = newTail;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore(); 

    string input;
    getline(cin, input);

    DoublyLinkedList list;

    istringstream iss(input);
    string word;
    while (iss >> word) {
        list.addToEnd(word);
    }

    list.rearrange(m);

    list.printList();

    return 0;
}