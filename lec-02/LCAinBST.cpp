#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/*
node *LCAinBST(node *root, node *p, node *Q)
{

    // base case;

    if(root == NULL)
    return NULL;

    if (root->data < p->data && root->data < Q->data)
        return LCAinBST(root->right, p, Q);

    if (root->data > p->data && root->data > Q->data)
        return LCAinBST(root->left, p, Q);

    return root;
}


*/

node *LCAinBST(node *root, node *p, node *Q)
{

    while (root != NULL)
    {

        if (root->data < p->data && root->data < Q->data)
            root = root->right;

        else if (root->data > p->data && root->data > Q->data)
            root = root->left;

        else
            return root;
    }
}

int main()
{

    return 0;
}