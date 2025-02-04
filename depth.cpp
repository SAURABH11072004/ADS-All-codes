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

// Function to calculate the depth of a specific node
int depthOfNode(node *root, int target, int depth)
{
    if (root == NULL)
        return -1; // Node not found
    
    // If the target node is found, return the depth
    if (root->data == target)
    {
        return depth;  // Return the depth of the node
    }

    // Otherwise, search in the left and right subtrees with incremented depth
    int leftDepth = depthOfNode(root->left, target, depth + 1);
    if (leftDepth != -1)
        return leftDepth;

    return depthOfNode(root->right, target, depth + 1);
}

int main()
{
    // Construct the tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    // Calculate and print the depth of a specific node (e.g., node with value 4)
    int targetValue = 4;
    int nodeDepth = depthOfNode(root, targetValue, 0);  // Start with depth = 0 (root node)
    
    if (nodeDepth != -1)
        cout << "The depth of node with value " << targetValue << " is: " << nodeDepth << endl;
    else
        cout << "Node with value " << targetValue << " not found." << endl;
    
    return 0;
}
