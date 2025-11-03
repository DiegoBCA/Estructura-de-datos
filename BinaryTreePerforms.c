#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/**
 * @brief Creates a new tree node with the given data.
 * * @param data The integer value to store in the new node.
 * @return struct Node* Pointer to the newly created node.
 */
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Initialize the node's fields
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

/**
 * @brief Performs a Pre-order traversal: Root -> Left -> Right.
 * * @param node The current node to process (starts at the root).
 */
void preOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    // 1. Visit the Root
    printf("%d ", node->data);
    
    // 2. Traverse the Left subtree
    preOrder(node->left);
    
    // 3. Traverse the Right subtree
    preOrder(node->right);
}

/**
 * @brief Performs an In-order traversal: Left -> Root -> Right.
 * * @param node The current node to process (starts at the root).
 */
void inOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    // 1. Traverse the Left subtree
    inOrder(node->left);
    
    // 2. Visit the Root
    printf("%d ", node->data);
    
    // 3. Traverse the Right subtree
    inOrder(node->right);
}

/**
 * @brief Performs a Post-order traversal: Left -> Right -> Root.
 * * @param node The current node to process (starts at the root).
 */
void postOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    // 1. Traverse the Left subtree
    postOrder(node->left);
    
    // 2. Traverse the Right subtree
    postOrder(node->right);
    
    // 3. Visit the Root
    printf("%d ", node->data);
}

/**
 * @brief Cleans up memory used by the tree nodes.
 * * @param node The current node to free (starts at the root).
 */
void freeTree(struct Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    // --- 1. Create a binary tree with at least 5 nodes (using 7 here) ---
    /*
             40
           /    \
          20     60
         / \    / \
        10  30 50  70
    */
    struct Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    // --- 2. Perform and print the traversals ---
    printf("Binary Tree Traversal Demonstration:\n");
    printf("The structure of the tree is:\n");
    printf("        40\n");
    printf("       /  \\\n");
    printf("      20    60\n");
    printf("     / \\  / \\\n");
    printf("    10  30 50  70\n\n");
    
    // Pre-order Traversal
    printf("Pre-order Traversal (Root, Left, Right): \n");
    preOrder(root);
    printf("\n\n");
    
    // In-order Traversal (produces sorted output in a BST)
    printf("In-order Traversal (Left, Root, Right): \n");
    inOrder(root);
    printf("\n\n");
    
    // Post-order Traversal
    printf("Post-order Traversal (Left, Right, Root): \n");
    postOrder(root);
    printf("\n\n");
    
    // Clean up memory
    freeTree(root);
    
    return 0;
}

