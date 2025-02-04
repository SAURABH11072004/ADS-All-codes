#include<iostream>
using namespace std;
struct abc{
    abc *left;
    abc *right;
    int val;
    abc(int value)
    {
        left=right=NULL;
        val=value;
    }
};
int countnodes(abc *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    return 1;
    return countnodes(root->left)+countnodes(root->right);
}
int main()
{
    abc *root=new abc(1);
   root->left = new abc(2);
    root->right = new abc(3);
    root->left->left = new abc(4);
    root->left->right = new abc(5);

      cout << countnodes(root) << "\n";  

    return 0;

}
