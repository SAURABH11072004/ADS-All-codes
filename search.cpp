#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

// Function to search a key in a BST
Node* search(Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Driver Code
int main() {
    // Creating a hardcoded tree for keeping the length of the code small.
    // Make sure that BST properties are maintained.
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // Search for key 19
    (search(root, 50) != NULL) ? cout << "Found\n" : cout << "Not Found\n";

    // Search for key 80
    (search(root, 80) != NULL) ? cout << "Found\n" : cout << "Not Found\n";

    return 0;
}
