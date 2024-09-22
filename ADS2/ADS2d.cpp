#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int value;
    int count;
    Node* next;
    Node(int val){
        value = val;
        count =1;
        next = nullptr;
    }
};

class linkedlist{
    private:
    Node* head;

    public:
    linkedlist(){
        head = nullptr;
    }

    void addtoend(int val){
        Node* temp =head;
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->value == val) {
                temp->count++; 
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        if (prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        
    }

    vector<int> findModes() {
        vector<int> modes;
        int maxCount = 0;

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->count > maxCount) {
                maxCount = temp->count;
            }
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            if (temp->count == maxCount) {
                modes.push_back(temp->value);
            }
            temp = temp->next;
        }

        return modes;
    }

    ~linkedlist() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};


int main(){
    int n;
    cin>> n;
    linkedlist list;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        list.addtoend(num);
    }

    vector<int> modes = list.findModes();
    sort(modes.begin(), modes.end(), greater<int>());

    for (int mode : modes) {
        cout << mode << " ";
    }
}