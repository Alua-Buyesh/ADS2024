#include <iostream>
#include <vector>
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

// Подсчет уровней и суммы значений на каждом уровне
void levelSums(Node* root, vector<int>& sums) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int currentLevelSum = 0;

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            currentLevelSum += current->key;

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        sums.push_back(currentLevelSum);
    }
}

int main() {
    int n;
    cin >> n; // Размер последовательности
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    vector<int> sums;
    levelSums(root, sums);

    cout << sums.size() << endl; // Количество уровней
    for (int sum : sums) {
        cout << sum << " "; // Суммы по уровням
    }
    cout << endl;

    return 0;
}
