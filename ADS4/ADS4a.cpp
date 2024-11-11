#include <iostream>
#include <vector>
#include <string>
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

// Проверка доступности пути
bool checkPath(Node* root, const string& path) {
    Node* current = root;
    for (char turn : path) {
        if (current == nullptr) {
            return false; // Путь недоступен, узел не существует
        }
        if (turn == 'L') {
            current = current->left; // Переход к левому ребенку
        } else if (turn == 'R') {
            current = current->right; // Переход к правому ребенку
        }
    }
    return current != nullptr; // Проверка, достигли ли мы узла
}

int main() {
    int n, m;
    cin >> n >> m; // Число узлов и количество путей
    Node* root = nullptr;

    // Чтение узлов и построение дерева
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    // Чтение и проверка каждого пути
    for (int i = 0; i < m; ++i) {
        string path;
        cin >> path; // Чтение пути
        if (checkPath(root, path)) {
            cout << "YES" << endl; // Путь доступен
        } else {
            cout << "NO" << endl; // Путь недоступен
        }
    }

    return 0;
}
