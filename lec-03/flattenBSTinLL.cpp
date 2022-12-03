#include <iostream>
#include <vector>
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

void inorder(node *root, vector<int> &in)
{

    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

node *flatten(node *root)
{

    vector<int> inorderVal;
    int n = inorderVal.size();

    // store thr sorted value;
    inorder(root, inorderVal);

    node *newRoot = new node(inorderVal[0]);
    node *curr = newRoot;

    // 2nd step ;
    for (int i = 1; i < n; i++)
    {

        node *temp = new node(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // 3rd step;
    curr->left = NULL;
    curr->right = NULL;
}

int main()
{

    return 0;
}