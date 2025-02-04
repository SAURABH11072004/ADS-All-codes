#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node * right;
    node(int val)
    {
        left=right=NULL;
        data=val;
    }
};
int height(node *root)
{
    if(root==NULL)
    return -1;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}
int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    cout<<"The height of of aq binary tree is-"<<height(root);
    return 0;
}
