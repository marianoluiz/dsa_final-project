#include <iostream>
#include <stack>


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

Node* createNode(int value) {
    return new Node(value);
}

Node* insertNode(Node* root, int value) {
    if (!root) {
        return createNode(value);
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
    if (!root || root->data == value) {
        return root;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);

    int searchValue = 7;
    Node* result = search(root, searchValue);
    if (result != NULL) {
        std::cout << "Value " << searchValue << " found in the tree." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    deleteTree(root);

    return 0;
}

