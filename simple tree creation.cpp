#include <iostream>
using namespace std;

// Definition of the tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
    // Constructing the binary tree
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    // Creating the root node
    Node* root = new Node(1);

    // Creating left and right children of the root node
    root->left = new Node(2);
    root->right = new Node(3);

    // Creating left and right children of node 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // At this point, the tree is constructed, but no traversal is done.
    // The tree structure is:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    // No traversal or print statements here; just constructing the tree.
    
    return 0;
}
