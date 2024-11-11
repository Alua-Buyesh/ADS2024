#include <iostream>
#include <queue>
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

// Подсчет числа "маленьких треугольников"
int countSmallTriangles(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            // Если текущий узел имеет оба дочерних узла, он образует треугольник
            if (current->left != nullptr && current->right != nullptr) {
                count++;
            }

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n; // Число узлов
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    int result = countSmallTriangles(root);
    cout << result << endl;

    return 0;
}
