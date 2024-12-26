#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

struct TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* current = st.top();
        st.pop();
        cout << current->data << " ";

        if (current->right != NULL) {
            st.push(current->right);
        }
        if (current->left != NULL) {
            st.push(current->left);
        }
    }
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != NULL || !st.empty()) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> st;
    TreeNode* current = root;
    TreeNode* peek = NULL;
    TreeNode* rightChild = NULL;

    do {
        while (current != NULL) {
            if (current->right != NULL) {
                st.push(current->right);
            }
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        peek = st.empty() ? NULL : st.top();

        if (current->right != NULL && current->right == peek) {
            rightChild = current;
            current = st.top();
            st.pop();
            st.push(rightChild);
        } else {
            cout << current->data << " ";
            current = NULL;
        }
    } while (!st.empty());
}

int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(25);
    root->right = createNode(49);
    root->left->left = createNode(96);
    root->left->right = createNode(13);
    root->left->left->left = createNode(84);
    root->left->left->right = createNode(69);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

