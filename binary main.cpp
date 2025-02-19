#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert
void insert(Node*& root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(key);
            return;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(key);
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Search
bool search(Node* root, int key) {
    if (root == nullptr) return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == key) return true;

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    return false;
}

// Delete deepest node
void deleteDeepest(Node* root, Node* delNode) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == delNode) {
            temp = nullptr;
            delete delNode;
            return;
        }

        if (temp->right) {
            if (temp->right == delNode) {
                temp->right = nullptr;
                delete delNode;
                return;
            } else {
                q.push(temp->right);
            }
        }

        if (temp->left) {
            if (temp->left == delNode) {
                temp->left = nullptr;
                delete delNode;
                return;
            } else {
                q.push(temp->left);
            }
        }
    }
}

// Delete node
void deleteNode(Node*& root, int key) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    Node* keyNode = nullptr;
    Node* temp;
    Node* lastNode;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key) keyNode = temp;

        if (temp->left) {
            lastNode = temp->left;
            q.push(temp->left);
        }

        if (temp->right) {
            lastNode = temp->right;
            q.push(temp->right);
        }
    }

    if (keyNode) {
        keyNode->data = lastNode->data;
        deleteDeepest(root, lastNode);
    }
}

// Display function (Inorder Traversal)
void display(Node* root) {
    if (root == nullptr) return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main() {
    Node* root = nullptr;
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    
    cout << "Tree (Inorder Traversal): ";
    display(root);
    cout << endl;

    cout << "Search 5: " << (search(root, 5) ? "Found" : "Not Found") << endl;
    
    deleteNode(root, 3);
    
    cout << "Tree after deleting 3 (Inorder Traversal): ";
    display(root);
    cout << endl;

    return 0;
}
