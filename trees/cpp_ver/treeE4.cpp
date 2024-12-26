#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val): data(val), left(NULL), right(NULL){}
};

struct StackNode {
	TreeNode* data;
	StackNode* next; 
	StackNode(TreeNode* val): data(val), next(NULL) {}
};

TreeNode* createNode(int data){
	return new TreeNode(data);
}

StackNode* createStackNode(TreeNode* data) {
    return new StackNode(data);
}

void push(StackNode*& top, TreeNode* data) {
    StackNode* newNode = createStackNode(data);
    newNode->next = top;
    top = newNode;
}

TreeNode* pop(StackNode*& top) {
    if (top == NULL) return NULL;
    StackNode* temp = top;
    top = top->next;
    TreeNode* popped = temp->data;
    delete(temp);
    return popped;
}

int isEmpty(StackNode* top) {
    return top == NULL;
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    StackNode* stack = NULL;
    TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            cout << current->data << " ";
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        current = current->right;
    }
}
void inorder(TreeNode* root) {
    if (root == NULL) return;
    StackNode* stack = NULL;
    TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        cout << current->data << " ";
        current = current->right;
    }
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    StackNode* stack = NULL;
    TreeNode* current = root;
    TreeNode* peek = NULL;
    TreeNode* rightChild = NULL;

    do {
        while (current != NULL) {
            if (current->right) {
                push(stack, current->right);
            }
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        peek = isEmpty(stack) ? NULL : stack->data;

        if (current->right != NULL && current->right == peek) {
            rightChild = pop(stack);
            push(stack, current);
            current = current->right;
        } else {
            cout << current->data << " ";
            current = NULL;
        }
    } while (!isEmpty(stack));
}

int main() {
    TreeNode* root = createNode(95);
    root->left= createNode(15);
    root->left->left = createNode(35);
    root->left->left->left = createNode(67);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}
