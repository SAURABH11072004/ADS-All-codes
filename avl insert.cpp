#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

   Node(int value) {
    data = value;    // Assign value to the 'data' member
    left = nullptr;   // Initialize 'left' pointer to nullptr
    right = nullptr;  // Initialize 'right' pointer to nullptr
    height = 1;       // Set height to 1 (because a new node is a leaf node)
}

};

struct AVLTree {
    Node* root;

    AVLTree(){ root=nullptr; }

    int height(Node* node) {
    if (node != nullptr) {
        return node->height;
    }
    return 0;
}


    // Helper function to calculate the balance factor
    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Insert a node
    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else // Duplicate keys are not allowed in the AVL tree
            return node;

        // Update height of this node
        node->height = max(height(node->left), height(node->right)) + 1;

        // Balance the node
        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Insert function that starts from the root
    void insert(int key) {
        root = insert(root, key);
    }

    // In-order traversal of the tree
    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    cout << "In-order traversal of the AVL Tree is: ";
    tree.display();

    return 0;
}
