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

// Function to calculate the height of the tree
int calculateHeight(Node* root) {
    // Base case: if the tree is empty, return -1 (or 0 depending on your definition)
    if (root == nullptr) {
        return -1;  // Return -1 if height is considered as number of edges
        // Return 0 if height is considered as the number of nodes along the path
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    // The height of the tree is the maximum of left and right subtrees' height + 1 for the current node
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // Create a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    // Calculate and display the height of the tree
    cout << "Height of the tree: " << calculateHeight(root) << endl;

    return 0;
}
