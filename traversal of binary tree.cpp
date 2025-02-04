#include<iostream>
using namespace std;

struct treenode
{
    int value;
    treenode* left;
    treenode* right;

    treenode(int val)
    {
        value=val;
        left=nullptr;
        right=nullptr;
    }
};

treenode *create(int value)
{
    return new treenode(value);
}

void preorder(treenode *node)
{
    if(node==nullptr)
    {
        return;
    }
    cout<<node->value<<" ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    treenode* root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    preorder(root);
    return 0;
}
