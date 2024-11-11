#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};

// Вставка узла в BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Функция для подсчета размера поддерева
int subtreeSize(Node* root) {
    if (root == nullptr) {
        return 0; // Если узел пустой, размер 0
    }
    // Рекурсивный подсчет размера поддерева
    return 1 + subtreeSize(root->left) + subtreeSize(root->right);
}

// Функция для поиска узла и получения его размера поддерева
int findSubtreeSize(Node* root, int key) {
    if (root == nullptr) {
        return 0; // Узел не найден
    }
    if (root->key == key) {
        return subtreeSize(root); // Возвращаем размер поддерева узла
    }
    // Рекурсивный поиск узла
    if (key < root->key) {
        return findSubtreeSize(root->left, key);
    } else {
        return findSubtreeSize(root->right, key);
    }
}

int main() {
    int n;
    cin >> n; // Число узлов
    Node* root = nullptr;

    // Чтение узлов и построение дерева
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int x;
    cin >> x; // Узел, для которого нужно найти размер поддерева

    // Получение и вывод размера поддерева узла x
    int size = findSubtreeSize(root, x);
    cout << size << endl;

    return 0;
}
