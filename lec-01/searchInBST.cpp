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

//  T.C = O(N) ans S.C = O(N) in worst case;
bool searchInBST(node *root, int x)
{

    // base case

    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (root->data > x)
    {

        // data present int the left part;
        return searchInBST(root->left, x);
    }

    else
    {

        // data preesent in the right part of bst;
        return searchInBST(root->right, x);
    }
}

*/


// time complexity will be same but sapce complexity is O(1);
bool searchInBST(node *root, int x)
{


    node*temp = root;

    while(temp != NULL){

        if(temp->data == x)
        return true;

        if(temp->data > x){
            temp = temp->left;
        }

        else{
            temp = temp->right;
        }
    }

    return false;
}

int main()
{

    return 0;
}