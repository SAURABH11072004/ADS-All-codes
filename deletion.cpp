#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};


Node* getSuccessor(Node* curr) {
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}


Node* delNode(Node* root, int x) {
    
    if (root == nullptr)
        return root;

    
    if (root->key > x)
        root->left = delNode(root->left, x);
    
    else if (root->key < x)
        root->right = delNode(root->right, x);
    
    else {
       
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        
        Node* succ = getSuccessor(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
    }

    return root;
}


void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int x = 70;

    
    root = delNode(root, x);

   
    inorder(root);
    
    return 0;
}
