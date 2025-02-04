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

    // Normal BST deletion
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        // Perform the normal BST delete
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {  // Node to be deleted is found
            // Case 1: Node with only one child or no child
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node with two children
            // Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }

        // Update height of the current node
        root->height = max(height(root->left), height(root->right)) + 1;

        // Balance the node if it becomes unbalanced
        int balance = balanceFactor(root);

        // Left Left Case
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Helper function to delete a node
    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    // Function to get the node with the minimum value (in-order successor)
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
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

    // Take user input to delete a node
    int delValue;
    cout << "Enter the value to delete: ";
    cin >> delValue;

    // Delete the node
    tree.deleteValue(delValue);

    cout << "In-order traversal after deletion: ";
    tree.display();

    return 0;
}
