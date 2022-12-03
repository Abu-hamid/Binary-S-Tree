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





node*minVal(node*root){

    node*temp = root;

    while(temp->left != NULL){

        temp = temp->left;
    }

    return temp;
}


node*maxVal(node*root){

    node*temp = root;

    while(temp->right != NULL){

        temp = temp->right;
    }

    return temp;
}

int main(){

return 0;
}