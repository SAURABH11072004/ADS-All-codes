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
    // If the tree is empty, create the root node
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    // Use a queue to perform level-order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front(); // Get the front node
        q.pop(); // Remove the front node from the queue

        // Check if the left child exists and enqueue it
        if (current->left != nullptr) {
            q.push(current->left);
        } else {
            // If the left child doesn't exist, insert the new node here
            current->left = new Node(value);
            return;
        }

        // Check if the right child exists and enqueue it
        if (current->right != nullptr) {
            q.push(current->right);
        } else {
            // If the right child doesn't exist, insert the new node here
            current->right = new Node(value);
            return;
        }
    }
}

// Function for level-order traversal of the binary tree
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front(); // Get the front node
        q.pop(); // Remove the front node from the queue

        cout << current->data << " "; // Print the current node's data

        // Check if the left child exists and enqueue it
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Check if the right child exists and enqueue it
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl; // End of level-order traversal
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

    // Print the tree using level-order traversal
    cout << "Level-order traversal after insertion: ";
    levelOrderTraversal(root);

    return 0;
}
