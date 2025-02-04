#include<iostream>
using namespace std;

struct treenode
{
    int value;
    treenode* left;
    treenode* right;

    treenode(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

treenode *create(int value)
{
    return new treenode(value);
}

// Preorder Traversal (Root, Left, Right)
void preorder(treenode *node)
{
    if(node == nullptr)
    {
        return;
    }
    cout << node->value << " "; // Visit root
    preorder(node->left); // Traverse left subtree
    preorder(node->right); // Traverse right subtree
}

// Inorder Traversal (Left, Root, Right)
void inorder(treenode *node)
{
    if(node == nullptr)
    {
        return;
    }
    inorder(node->left); // Traverse left subtree
    cout << node->value << " "; // Visit root
    inorder(node->right); // Traverse right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorder(treenode *node)
{
    if(node == nullptr)
    {
        return;
    }
    postorder(node->left); // Traverse left subtree
    postorder(node->right); // Traverse right subtree
    cout << node->value << " "; // Visit root
}

int main()
{
    // Create the tree
    treenode* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    // Preorder traversal
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    // Inorder traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Postorder traversal
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
