#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into the BST
TreeNode* insert(TreeNode* node, int value) {
    // If the tree is empty, create a new node
    if (node == nullptr) {
        return new TreeNode(value);
    }

    // If value is less than the node value, insert it in the left subtree
    if (value < node->value) {
        node->left = insert(node->left, value);
    }
    // If value is greater than the node value, insert it in the right subtree
    else {
        node->right = insert(node->right, value);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Pre-order traversal (Root, Left, Right)
void preOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->value << " ";   // Print current node's value
    preOrder(node->left);         // Recur on left child
    preOrder(node->right);        // Recur on right child
}

// In-order traversal (Left, Root, Right)
void inOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);          // Recur on left child
    cout << node->value << " ";   // Print current node's value
    inOrder(node->right);         // Recur on right child
}

// Post-order traversal (Left, Right, Root)
void postOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->left);        // Recur on left child
    postOrder(node->right);       // Recur on right child
    cout << node->value << " ";   // Print current node's value
}

int main() {
    TreeNode* root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    cout << "Pre-order traversal: ";
    preOrder(root);  // Output: 5 3 2 4 7 6 8
    cout << endl;

    cout << "In-order traversal: ";
    inOrder(root);   // Output: 2 3 4 5 6 7 8
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root); // Output: 2 4 3 6 8 7 5
    cout << endl;

    return 0;
}
