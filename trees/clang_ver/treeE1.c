#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* data;
    struct StackNode* next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct StackNode* createStackNode(struct TreeNode* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct StackNode** top, struct TreeNode* data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL) return NULL;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct TreeNode* popped = temp->data;
    free(temp);
    return popped;
}

int isEmpty(struct StackNode* top) {
    return top == NULL;
}

void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

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
    struct TreeNode* root = createNode(10);
    root->left = createNode(25);
    root->right = createNode(49);
    root->left->left = createNode(96);
    root->left->right = createNode(13);
    root->left->left->left = createNode(84);
    root->left->left->right = createNode(69);

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
