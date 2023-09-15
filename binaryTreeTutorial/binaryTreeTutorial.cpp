#include <iostream>

struct n {
    int data;
    n* left;
    n* right;
};
typedef n node;

node* add(node* tree, int x) {
    if (tree == NULL) {
        node* root = (node*)malloc(sizeof(node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (tree->data < x) {
        tree->right = add(tree->right, x);
        return tree;
    }
    tree->left = add(tree->left, x);
    return tree;
}

void traverse(node* tree) {  // LNR (left-node-right)
    if (tree == NULL) {
        return;
    }
    traverse(tree->left);
    printf("%d ", tree->data);
    traverse(tree->right);
}

int IsThere(node* tree, int target) {
    if (tree == NULL) {
        return -1;
    }
    if (tree->data == target) {
        return 1;
    }
    if (IsThere(tree->right, target) == 1) {
        return 1;
    }
    if (IsThere(tree->left, target) == 1) {
        return 1;
    }
    return -1;
}

int main()
{
    node* tree = NULL;
    tree = add(tree, 12);
    tree = add(tree, 24);
    tree = add(tree, 27);
    tree = add(tree, 18);
    tree = add(tree, 26);
    tree = add(tree, 28);
    tree = add(tree, 56);
    tree = add(tree, 190);
    tree = add(tree, 200);
    tree = add(tree, 213);
    traverse(tree);
    printf("target has: %d ", IsThere(tree, 13));
}

