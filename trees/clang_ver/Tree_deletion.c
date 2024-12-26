#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree:\n");
    inorder(root);
    printf("\n");

    printf("Deleting node with key 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    printf("Deleting node with key 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    printf("Deleting node with key 50 (root)\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

