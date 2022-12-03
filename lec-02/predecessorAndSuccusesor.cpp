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

pair<int, int> predSucc(node *root, int key)
{

    int pred = -1;
    int succ = -1;
    // find key

    node *temp = root;

    while (temp != NULL)
    {

        if (temp->data > key)
        {
            succ = temp->data;// first save the data ans then move the temp value for more data nde;
            temp = temp->left;
            
        }
    else
        {
            pred = temp->data;
            temp = temp->right;
            
        }
    }


    // pred and succ;
    node *leftTree = temp->left;

    while (leftTree != NULL)
    {

        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ;
    node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->right;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}
int main()
{

    return 0;
}