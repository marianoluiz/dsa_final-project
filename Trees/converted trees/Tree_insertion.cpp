#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Inorder traversal of the binary search tree:\n";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Deleting node with key 20\n";
    root = deleteNode(root, 20);
    std::cout << "Inorder traversal after deletion:\n";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Deleting node with key 30\n";
    root = deleteNode(root, 30);
    std::cout << "Inorder traversal after deletion:\n";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Deleting node with key 50 (root)\n";
    root = deleteNode(root, 50);
    std::cout << "Inorder traversal after deletion:\n";
    inorder(root);
    std::cout << std::endl;

    // Freeing memory
    std::cout << "Freeing memory\n";
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
