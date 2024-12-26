#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;  
    newNode->right = NULL; 
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) { 
        return createNode(value);
    } else {
        if (value <= root->data) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
        return root;
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) { 
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL; 

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    std::cout << "\nInorder traversal of the binary tree: \n\n";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
