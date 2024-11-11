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

// Вставка дочерних узлов в дерево
void insert(Node* nodes[], int parent, int child, int isLeft) {
    if (nodes[parent] == nullptr) {
        nodes[parent] = new Node(parent);
    }
    nodes[child] = new Node(child);
    if (isLeft) {
        nodes[parent]->left = nodes[child];
    } else {
        nodes[parent]->right = nodes[child];
    }
}

// Подсчет максимальной ширины уровня дерева
int getMaxWidth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        maxWidth = max(maxWidth, levelSize);

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    return maxWidth;
}

int main() {
    int n;
    cin >> n; // Число ребер
    Node* nodes[1001] = {nullptr}; // Массив указателей на узлы, размерность 1001 для учета индексации с 1

    for (int i = 0; i < n; ++i) {
        int parent, child, isLeft;
        cin >> parent >> child >> isLeft;
        insert(nodes, parent, child, isLeft);
    }

    int result = getMaxWidth(nodes[1]);
    cout << result << endl;

    return 0;
}
