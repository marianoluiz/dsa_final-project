#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Definition for stack node
struct StackNode {
    struct TreeNode* data;
    struct StackNode* next;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new stack node
struct StackNode* createStackNode(struct TreeNode* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node to the stack
void push(struct StackNode** top, struct TreeNode* data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL) return NULL;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct TreeNode* popped = temp->data;
    free(temp);
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Preorder traversal
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;
                                  //top != null
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            printf("%d ", current->data);
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        current = current->right;
    }
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Postorder traversal
void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;
    struct TreeNode* peek = NULL;
    struct TreeNode* rightChild = NULL;

    do {
        while (current != NULL) {
            if (current->right) {
                push(&stack, current->right);
            }
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        peek = isEmpty(stack) ? NULL : stack->data;

        if (current->right != NULL && current->right == peek) {
            rightChild = pop(&stack);
            push(&stack, current);
            current = current->right;
        } else {
            printf("%d ", current->data);
            current = NULL;
        }
    } while (!isEmpty(stack));
}

int main() {
    // Create nodes
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform depth-first traversals
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
