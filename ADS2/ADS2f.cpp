#include <iostream>
using namespace std;

// Определение структуры узла
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Функция для вставки узла на указанную позицию
Node* insertNode(Node* head, int data, int position) {
    // Создаем новый узел
    Node* newNode = new Node(data);
    
    // Если вставка в начало (позиция 0)
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    
    // Идем по списку до нужной позиции
    Node* current = head;
    for (int i = 1; i < position && current != nullptr; ++i) {
        current = current->next;
    }
    
    // Вставляем новый узел на нужную позицию
    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }
    
    return head; // Возвращаем голову списка
}

// Функция для печати связанного списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n; // Количество элементов в списке
    
    Node* head = nullptr;
    Node* tail = nullptr;

    // Считываем элементы списка
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int data, position;
    cin >> data >> position; // Считываем данные нового узла и позицию
    
    // Вставляем узел в нужную позицию
    head = insertNode(head, data, position);
    
    // Выводим обновленный список
    printList(head);

    return 0;
}
