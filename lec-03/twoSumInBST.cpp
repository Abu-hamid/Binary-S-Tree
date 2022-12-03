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

void inorder(node*root , vector<int> &in){

    if(root == NULL)
    return;

    inorder(root->left ,in);
    in.push_back(root->data);
    inorder(root->right , in);
    
}


bool twoSumBST(node*root , int target){

    vector<int> inorderVal;

    // store thr sorted value;
    inorder(root , inorderVal);

   // use two pointer approach for traversal;
    int i = 0 ;
    int j = inorderVal.size()-1;

    while(i<j){

        int sum = inorderVal[i] + inorderVal[j];

        if(sum == target){

            return true;
        }

        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }

    return false;
}
int main(){

return 0;
}