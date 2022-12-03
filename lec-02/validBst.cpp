#include<iostream>
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

bool isBST(node*root , int min, int max){

    // base case;

    if(root == NULL){
        return true;

    }

    if(root->data >= min && root->data <= max){

        bool left = isBST(root->left , min , root->data);
        bool right = isBST(root->right , root->data , max);

        return left && right;
    }

    else{

        return false;
    }
}


bool validateBST(node*root){

    return isBST(root , INT_MIN , INT_MAX);

}

int main(){

return 0;
}