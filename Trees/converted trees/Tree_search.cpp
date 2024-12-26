#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    } else {
        if (value <= root->data) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);

    int searchValue = 7;
    Node* result = search(root, searchValue);
    if (result != nullptr) {
        std::cout << "Value " << searchValue << " found in the tree." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    return 0;
}
