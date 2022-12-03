#include<iostream>
#include<vector>
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

node*inorderToBST(int s , int e , vector<int> &inorderS){

    // base case;

    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;

    node*root = new node(inorderS[mid]);

    root->left = inorderToBST(s , mid-1 , inorderS);
    root->right = inorderToBST(mid+1 , e, inorderS);

    return root;
}

node*balancedBST(node*root){

    vector<int> inorderVal;
    int n = inorderVal.size();

    // store thr sorted value;
    inorder(root, inorderVal);

    return inorderToBST(0 , n-1 , inorderVal);

}

int main(){

return 0;
}