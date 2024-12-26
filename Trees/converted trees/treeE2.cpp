#include <iostream>
#include <stack>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

struct StackNode {
    TreeNode* data;
    StackNode* next;
};

StackNode* createStackNode(TreeNode* data) {
    StackNode* newNode = new StackNode;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void push(StackNode** top, TreeNode* data) {
    StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

TreeNode* pop(StackNode** top) {
    if (*top == nullptr) return nullptr;
    StackNode* temp = *top;
    *top = (*top)->next;
    TreeNode* popped = temp->data;
    delete temp;
    return popped;
}

bool isEmpty(StackNode* top) {
    return top == nullptr;
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
            if (current->right) {
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
            current = rightChild->right;
        } else {
            std::cout << current->data << " ";
            current = nullptr;
        }
    } while (!stack.empty());
}

int main() {
    TreeNode* root = createNode(27);
    root->left = createNode(41);
    root->right = createNode(18);
    root->left->left = createNode(54);
    root->left->right = createNode(28);
    root->right->right = createNode(76);

    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << std::endl;

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
