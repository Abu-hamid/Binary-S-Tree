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

node *minVal(node *root)
{

    node *temp = root;

    while (temp->left != NULL)
    {

        temp = temp->left;
    }

    return temp;
}

node *deleteFromBST(node *root, int val)
{

    // base case;
    if (root == NULL)
        return root;

    if (root->data == val)
    {
        // 0 child;
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child;

        // left child;

        if (root->left != NULL && root->right == NULL)
        {

            node *temp = root->left;
            delete root;
            return temp;
        }

        // right chill;

        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child;

        int mini = minVal(root->right)->data;
        root->data = mini; // copy the root data with min. value of the right child;
        root->right = deleteFromBST(root->right, mini);
        return root;
    }

    else if (root->data > val)
    {

        root->left = deleteFromBST(root->left, val);
        return root;
    }

    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
int main()
{

    return 0;
}