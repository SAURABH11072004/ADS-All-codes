#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node into the binary tree
void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left != nullptr) {
            q.push(current->left);
        } else {
            current->left = new Node(value);
            return;
        }

        if (current->right != nullptr) {
            q.push(current->right);
        } else {
            current->right = new Node(value);
            return;
        }
    }
}

// Function to delete a node in the binary tree
void deleteNode(Node*& root, int key) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        // If the tree has only one node (the root)
        delete root;
        root = nullptr;
        return;
    }

    // Perform level-order traversal to find the node to delete
    queue<Node*> q;
    q.push(root);

    Node* nodeToDelete = nullptr;
    Node* deepestNode = nullptr;

    while (!q.empty()) {
        deepestNode = q.front();
        q.pop();

        // If we find the node to delete
        if (deepestNode->data == key) {
            nodeToDelete = deepestNode;
        }

        if (deepestNode->left) q.push(deepestNode->left);
        if (deepestNode->right) q.push(deepestNode->right);
    }

    if (nodeToDelete != nullptr) {
        // Replace the node's data with the deepest node's data
        nodeToDelete->data = deepestNode->data;

        // Delete the deepest node
        delete deepestNode;
    }
}

// Function to perform level-order traversal of the binary tree
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the binary tree
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);

    cout << "Level-order traversal before deletion: ";
    levelOrderTraversal(root);

    // Delete node with value 2
    deleteNode(root, 2);

    cout << "Level-order traversal after deletion: ";
    levelOrderTraversal(root);

    return 0;
}
