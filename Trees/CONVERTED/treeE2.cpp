#include <iostream>
#include <stack>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void preorder(TreeNode* root) {
    if (root == NULL) return;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != NULL || !stack.empty()) {
        while (current != NULL) {
            std::cout << current->data << " ";
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        current = current->right;
    }
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != NULL || !stack.empty()) {
        while (current != NULL) {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        std::cout << current->data << " ";
        current = current->right;
    }
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    TreeNode* peek = NULL;
    TreeNode* rightChild = NULL;

    do {
        while (current != NULL) {
            if (current->right) {
                stack.push(current->right);
            }
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        peek = stack.empty() ? NULL : stack.top();

        if (current->right != NULL && current->right == peek) {
            rightChild = stack.top();
            stack.pop();
            stack.push(current);
            current = current->right;
        } else {
            std::cout << current->data << " ";
            current = NULL;
        }
    } while (!stack.empty());
}

int main() {
    TreeNode* root = new TreeNode(27);
    root->left = new TreeNode(41);
    root->right = new TreeNode(18);
    root->left->left = new TreeNode(54);
    root->left->right = new TreeNode(28);
    root->right->right = new TreeNode(76);

    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << std::endl;

    return 0;
}


