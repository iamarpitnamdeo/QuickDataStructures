#include <iostream>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *lchild;
    BstNode *rchild;
    BstNode(int data)
    {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
    }
};

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        BstNode *temp = new BstNode(data);
        root = temp;
    }
    else if (data <= root->data)
    {
        root->lchild = Insert(root->lchild, data);
    }
    else
    {
        root->rchild = Insert(root->rchild, data);
    }
    return root;
}
// recursive approach to find the smallest element
int rsmallest(BstNode *root)
{
    if (root->lchild == NULL)
    {
        return root->data;
    }
    return rsmallest(root->lchild);
}
// iterative approach of finding the smallest element
int smallest(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return -1;
    }
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root->data;
}

// iterative approach of finding the largest element
int largest(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree";
        return -1;
        exit(0);
    }
    while (root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root->data;
}
int main()
{
    BstNode *root = NULL;
    root = Insert(root, 12);
    root = Insert(root, 10);
    root = Insert(root, 15);
    root = Insert(root, 11);
    root = Insert(root, 9);
    root = Insert(root, 18);
    root = Insert(root, 13);
    cout << "Smallest Element in the BST is ";
    cout << rsmallest(root);
    cout << "Largest Element in the BST is ";
    cout << largest(root);
    return 0;
}