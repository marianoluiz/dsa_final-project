#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node *deleteNode(Node *root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the binary search tree:\n";
    inorder(root);
    cout << "\n";

    cout << "Deleting node with key 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal after deletion:\n";
    inorder(root);
    cout << "\n";

    cout << "Deleting node with key 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal after deletion:\n";
    inorder(root);
    cout << "\n";

    cout << "Deleting node with key 50 (root)\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal after deletion:\n";
    inorder(root);
    cout << "\n";

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

