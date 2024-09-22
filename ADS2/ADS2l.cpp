#include <iostream>

using namespace std;

// Структура для узла связного списка
struct Node {
    int value;
    Node* next;
    
    Node(int v) {
        value = v;
        next = nullptr;
    }
};

// Класс для односвязного списка
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Добавление элемента в конец списка
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Функция для нахождения подмассива с максимальной суммой
    int maxSubarraySum() {
        if (head == nullptr) return 0; // если список пуст

        int maxSum = head->value;
        int currentSum = head->value;
        Node* temp = head->next;

        while (temp != nullptr) {
            // Продолжаем текущую сумму или начинаем новую
            currentSum = max(temp->value, currentSum + temp->value);
            // Обновляем максимальную сумму
            maxSum = max(maxSum, currentSum);
            temp = temp->next;
        }

        return maxSum;
    }

    // Деструктор для очистки памяти
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList list;

    // Чтение элементов и создание списка
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        list.append(value);
    }

    // Нахождение и вывод максимальной суммы подмассива
    cout << list.maxSubarraySum() << endl;

    return 0;
}
