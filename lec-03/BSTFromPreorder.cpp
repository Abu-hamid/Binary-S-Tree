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

node *solve(vector<int> &preorder, int mini, int maxi, int &i)
{

    // base case;

    if (i >= preorder.size())
        return NULL;

    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    node *root = new node(preorder[i]);

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

node *BSTFromPreorder(vector<int> &preorder)
{

    int mini = INT_MIN;
    int maxi = INT_MAX;

    int i = 0;
    return solve(preorder, mini, maxi, i);
}


// do without using the mini variable;
int main()
{

    return 0;
}