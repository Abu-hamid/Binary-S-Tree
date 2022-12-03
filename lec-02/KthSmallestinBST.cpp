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

int solve(node *root, int &i, int k)
{

    // base case;
    if (root == NULL)
    {
        return -1;
    }

    // l

    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    // N
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return solve(root->right, i, k);
}

// optimized by morris traversal
// code it by ownself;

int kthSmallest(node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);

    return ans;
}

int main()
{

    return 0;
}