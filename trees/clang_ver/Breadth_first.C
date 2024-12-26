#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for a queue node
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// Structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct TreeNode* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a tree node into the queue
void enqueue(struct Queue* q, struct TreeNode* data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue a tree node from the queue
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = q->front;
    struct TreeNode* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to perform breadth-first traversal
void breadthFirstTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct Queue* q = createQueue();
    enqueue(q, root);
    while (q->front != NULL) {
        struct TreeNode* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }
    printf("\n");
}

int main() {
    // Create nodes
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform breadth-first traversal
    printf("Breadth-first traversal: ");
    breadthFirstTraversal(root);

    return 0;
}
