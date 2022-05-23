// program to check whether the binary tree is binary search tree or not
//  Approach 1 : check all the elements of left sub tree and right sub tree are smaller and greater respectively from root node and chek both left sub tree and right sub tree are bst or not
//  Approach 2 : provide range for each node and check elements are within that range or not
//  Approach 3 : inorder traversal of binary search tree will give a soted list
//  Approach 4 : find min and max element of left sub tree and righ sub tree.

// Approach 2
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int data)
    {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
    }
};
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *temp = new Node(data);
        root = temp;
    }
    else if (data <= root->data)
    {
        root->lchild = insert(root->lchild, data);
    }
    else
    {
        root->rchild = insert(root->rchild, data);
    }
    return root;
}
bool isBstUtil(Node *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;
    if (root->data > minVal && root->data < maxVal && isBstUtil(root->lchild, minVal, root->data) && isBstUtil(root->rchild, root->data, maxVal))
        return true;
    else
        return false;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 9);
    cout << isBstUtil(root, 0, 10);
    return 0;
}