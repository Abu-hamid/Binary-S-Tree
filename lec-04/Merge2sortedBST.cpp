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

/*

T.C =O(m+n) and S.C = O(M+N);

void inorder(node *root, vector<int> &in)
{

    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{

    vector<int> ans(a.size() + b.size());

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < a.size() && j < b.size())
    {

        if (i < j)
        {

            ans[k++] = a[i];
            i++;
        }

        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {

        ans[k++] = a[i];
        i++;
    }

    while (j < b.size())
    {

        ans[k++] = b[j];
        j++;
    }

    return ans;
}

node *inorderToBST(int s, int e, vector<int> &inorderS)
{

    // base case;

    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    node *root = new node(inorderS[mid]);

    root->left = inorderToBST(s, mid - 1, inorderS);
    root->right = inorderToBST(mid + 1, e, inorderS);

    return root;
}

*/

void convertIntoSortedDLL(node *root, node *&head)
{

    // base case;
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

node *mergeLinkedList(node *head1, node *head2)
{

    node *head = NULL;
    node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {

        if (head1->data < head2->data)
        {

            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }

            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }

        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {

        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNode(node*head){

    int count = 0;
    node*temp = head;

    while(temp != NULL){

        count++;
        temp = temp->right;

    }
    return count;
}

node *sortedLLToBST(node *head, int n)
{

    // base case;

    if (head == NULL || n <= 0)
        return NULL;

    node *left = sortedLLToBST(head, n / 2);
    node *root = head;
    root->left = left;

    head = head->left;

    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

node *Merge2BST(node *root1, node *root2)
{

    /*
        // step 1: store inorder of the bst;
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);

        // step 2: merge two sorted inorder bst;
        vector<int> mergeArray = mergeArrays(bst1, bst2);

        // step3: use merge inorder to make merge bst ;
        int s = 0, e = mergeArray.size() - 1;
        return inorderToBST(s, e, mergeArray);

    */

    //    step 1: convert bst into ll;
    node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //  step 2: merge sorted linked list;
     node*head =  mergeLinkedList(head1 , head2);


    //  step 3: convert soreted linked list into BST;
    return sortedLLToBST(head , countNode(head));




}

int main()
{

    return 0;
}