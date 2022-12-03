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

// T.c O(logn)  
// inorder 
// preorder
// postorder is same as binary tree code is in previous binary lec. ;

node *insertIntoBST(node *root, int data)
{

    // base case ;

    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (data > root->data)
    {

        root->right = insertIntoBST(root->right, data); // insert in the right part of BST;
    }

    else
    {

        root->left = insertIntoBST(root->left, data); // insert in the left part of the BST;
    }

    return root;
}

void takeInpute(node *root)
{

    int data;
    cin >> data;

    while (data != -1)
    {

        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{

    return 0;
}
