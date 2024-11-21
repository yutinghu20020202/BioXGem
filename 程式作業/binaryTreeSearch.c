#include <stdio.h>
#include <stdlib.h>

// 節點結構定義
typedef struct Node {
    int value;              // 節點值
    struct Node* left;      // 左子樹
    struct Node* right;     // 右子樹
} Node;

// 建立新節點
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入節點到 BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value); // 如果是空樹，建立根節點
    }

    if (value < root->value) {
        root->left = insert(root->left, value); // 插入到左子樹
    } else {
        root->right = insert(root->right, value); // 插入到右子樹
    }

    return root;
}

// BST 搜尋函式
Node* search(Node* root, int target) {
    if (root == NULL || root->value == target) {
        return root; // 找到目標或樹為空
    }

    if (target < root->value) {
        return search(root->left, target); // 搜尋左子樹
    } else {
        return search(root->right, target); // 搜尋右子樹
    }
}

// 主程式
int main() {
    // 建立 BST
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 25);
    insert(root, 75);
    insert(root, 10);
    insert(root, 30);
    insert(root, 60);
    insert(root, 80);

    // 搜尋目標
    int target = 30;
    Node* result = search(root, target);

    if (result != NULL) {
        printf("Found %d in the BST.\n", result->value);
    } else {
        printf("%d not found in the BST.\n", target);
    }

    return 0;
}
