#include <iostream>
#include <stack>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
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
    if (root == nullptr) return;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
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
    if (root == nullptr) return;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    TreeNode* peek = nullptr;
    TreeNode* rightChild = nullptr;

    do {
        while (current != nullptr) {
            if (current->right != nullptr) {
                stack.push(current->right);
            }
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        peek = stack.empty() ? nullptr : stack.top();

        if (current->right != nullptr && current->right == peek) {
            rightChild = current;
            current = stack.top();
            stack.pop();
            stack.push(rightChild);
        } else {
            std::cout << current->data << " ";
            current = nullptr;
        }
    } while (!stack.empty());
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
