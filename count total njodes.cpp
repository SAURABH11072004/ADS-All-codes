#include<iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    int data;
    node(int val)
    {
        left=right=NULL;
        data=val;
    }
};
int count(node *root)
{
    if(root==NULL)
    return 0;
    int l=count(root->left);
    int r=count(root->right);
    return 1+l+r;
}
int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    cout<<"total number of nodes in a tree-"<<count(root);
    return 0;
}
