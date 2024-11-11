#include <iostream>
using namespace std;

// Структура узла дерева
struct Node {
    int key; // Ключ узла
    int count; // Множество ключей
    Node* left; // Указатель на левое поддерево
    Node* right; // Указатель на правое поддерево

    // Конструктор для создания узла
    Node(int value) {
        key = value;
        count = 1; // Изначально множество равно 1
        left = nullptr;
        right = nullptr;
    }
};

// Функция для вставки элемента в дерево
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        root->count++; // Увеличиваем множество, если ключ уже существует
    }

    return root;
}

// Функция для удаления элемента из дерева
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->count > 1) {
            root->count--; // Уменьшаем множество, если больше одной копии
            return root;
        }

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->key = temp->key;
            root->count = temp->count;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    return root;
}

// Функция для подсчета количества копий ключа
int count(Node* root, int key) {
    if (root == nullptr) {
        return 0;
    }

    if (key < root->key) {
        return count(root->left, key);
    } else if (key > root->key) {
        return count(root->right, key);
    } else {
        return root->count; // Возвращаем количество копий ключа
    }
}

int main() {
    Node* root = nullptr;

    int queries;
    cin >> queries;

    while (queries--) {
        string operation;
        int value;
        cin >> operation >> value;

        if (operation == "insert") {
            root = insert(root, value);
        } else if (operation == "delete") {
            root = deleteNode(root, value);
        } else if (operation == "cnt") {
            cout << count(root, value) << endl;
        }
    }

    return 0;
}
