#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    
    node(int val)
    {
        left = right = NULL;
        data = val;
    }
};

// Function to calculate the height of the tree (used to calculate height of a specific node)
int height(node *root)
{
    if (root == NULL)
        return -1;  // Return -1 for NULL (no node)
    
    int leftHeight = height(root->left);  // Calculate height of left subtree
    int rightHeight = height(root->right);  // Calculate height of right subtree
    
    // The height of the tree is the maximum of the heights of left and right subtrees plus 1
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate the height of a specific node
int heightOfNode(node *root, int target)
{
    if (root == NULL)
        return -1; // Node not found
    
    // If the target node is found, calculate its height
    if (root->data == target)
    {
        return height(root);  // Calculate and return the height of the node's subtree
    }

    // Otherwise, search in the left and right subtrees
    int leftHeight = heightOfNode(root->left, target);
    if (leftHeight != -1)
        return leftHeight;

    return heightOfNode(root->right, target);
}

int main()
{
    // Construct the tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    // Calculate and print the height of a specific node (e.g., node with value 2)
    int targetValue = 4;
    int nodeHeight = heightOfNode(root, targetValue);
    
    if (nodeHeight != -1)
        cout << "The height of node with value " << targetValue << " is: " << nodeHeight << endl;
    else
        cout << "Node with value " << targetValue << " not found." << endl;
    
    return 0;
}
