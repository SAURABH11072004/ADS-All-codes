#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

struct AVLTree {
    Node* root;

    AVLTree() : root(nullptr) {}

    int height(Node* node) {
        if (node != nullptr) {
            return node->height;
        }
        return 0;
    }

    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

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

    // In-order traversal to print tree
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

    // Insert a node in the AVL Tree
    Node* insert(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }

        if (key < node->data) {
            node->left = insert(node->left, key);
        }
        else if (key > node->data) {
            node->right = insert(node->right, key);
        }
        else {
            return node; // No duplicate values allowed
        }

        // Update height of this node
        node->height = max(height(node->left), height(node->right)) + 1;

        // Balance the node
        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->data) {
            return leftRotate(node);
        }

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

    // Helper function to insert a node
    void insert(int key) {
        root = insert(root, key);
    }

    // Search for a node with a given key
    Node* search(Node* node, int key) {
        // Base case: if node is null or key is found
        if (node == nullptr || node->data == key) {
            return node;
        }

        // If the key is smaller than the node's data, search the left subtree
        if (key < node->data) {
            return search(node->left, key);
        }
        // If the key is greater than the node's data, search the right subtree
        return search(node->right, key);
    }

    // Helper function to search for a node
    void searchValue(int key) {
        Node* result = search(root, key);
        if (result) {
            cout << "Node found: " << result->data << endl;
        } else {
            cout << "Node not found!" << endl;
        }
    }
};

int main() {
    AVLTree tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);

    cout << "In-order traversal of the AVL Tree is: ";
    tree.display();

    // Searching for nodes
    int searchValue;
    cout << "Enter the value to search for: ";
    cin >> searchValue;

    tree.searchValue(searchValue);

    return 0;
}
