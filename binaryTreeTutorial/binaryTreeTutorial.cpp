#include <iostream>

// Define a structure for a binary tree node
struct Node {
    int data;        // Data stored in the node
    Node* left;      // Pointer to the left child node
    Node* right;     // Pointer to the right child node
};

typedef Node node;   // Create an alias "node" for the "Node" structure

// Function to add a new node with data x to the binary tree
node* add(node* tree, int x) {
    if (tree == NULL) {
        // If the tree is empty, create a new root node
        node* root = new node; // Allocate memory for the new node
        root->data = x;       // Set the data of the new root node
        root->left = NULL;    // Initialize left child as NULL
        root->right = NULL;   // Initialize right child as NULL
        return root;          // Return the new root node
    }
    if (tree->data < x) {
        // If data is greater than the current node's data, insert in the right subtree
        tree->right = add(tree->right, x);
        return tree;
    }
    // Otherwise, insert in the left subtree
    tree->left = add(tree->left, x);
    return tree;
}

// Function to perform an in-order traversal of the binary tree (Left-Node-Right)
void traverse(node* tree) {
    if (tree == NULL) {
        return; // Base case: return if the tree is empty
    }
    traverse(tree->left);     // Recursively traverse the left subtree
    printf("%d ", tree->data); // Print the data of the current node
    traverse(tree->right);    // Recursively traverse the right subtree
}

// Function to check if a target value exists in the binary tree
int IsThere(node* tree, int target) {
    if (tree == NULL) {
        return -1; // Base case: return -1 if the tree is empty
    }
    if (tree->data == target) {
        return 1; // Return 1 if the target is found in the current node
    }
    // Recursively search in the right and left subtrees
    if (IsThere(tree->right, target) == 1 || IsThere(tree->left, target) == 1) {
        return 1; // Return 1 if the target is found in either subtree
    }
    return -1; // Return -1 if the target is not found in the tree
}

// Function to find the maximum value in the binary tree
int max(node* tree) {
    while (tree->right != NULL) {
        tree = tree->right; // Traverse to the rightmost node
    }
    return tree->data; // Return the data of the rightmost node
}

// Function to find the minimum value in the binary tree
int min(node* tree) {
    while (tree->left != NULL) {
        tree = tree->left; // Traverse to the leftmost node
    }
    return tree->data; // Return the data of the leftmost node
}

// Function to remove a node with value x from the binary tree
node* remove(node* tree, int x) {
    if (tree == NULL) {
        return NULL; // Base case: return NULL if the tree is empty
    }
    if (tree->data == x) {
        // If the node to be removed is found
        if (tree->left == NULL && tree->right == NULL) {
            // If it's a leaf node, simply return NULL to remove it
            return NULL;
        }
        if (tree->right != NULL) {
            // If it has a right subtree, replace the node's data with the minimum
            // value from the right subtree and remove that minimum node.
            tree->data = min(tree->right);
            tree->right = remove(tree->right, min(tree->right));
            return tree;
        }
        // If it has only a left subtree, do the same with the maximum value
        tree->data = max(tree->left);
        tree->left = remove(tree->left, max(tree->left));
        return tree;
    }
    if (tree->data < x) {
        tree->right = remove(tree->right, x); // Recursively remove from the right subtree
        return tree;
    }
    tree->left = remove(tree->left, x); // Recursively remove from the left subtree
    return tree;
}

int main() {
    node* tree = NULL; // Initialize an empty binary tree
    // Add nodes to the tree
    tree = add(tree, 69);
    tree = add(tree, 24);
    tree = add(tree, 72);
    tree = add(tree, 18);
    tree = add(tree, 26);
    tree = add(tree, 28);
    tree = add(tree, 56);
    tree = add(tree, 190);
    tree = add(tree, 200);
    tree = add(tree, 213);

    // Print the elements of the tree using in-order traversal
    traverse(tree);

    // Remove a node with value 69
    tree = remove(tree, 69);
    printf("\nRoot after removal: %d", tree->data);

    return 0;
}
