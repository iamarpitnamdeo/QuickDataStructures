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
BstNode *Insert(BstNode *root, int value)
{
    if (root == NULL)
    {
        BstNode *temp = new BstNode(value);
        root = temp;
    }
    else if (value <= root->data)
    {
        root->lchild = Insert(root->lchild, value);
    }
    else
    {
        root->rchild = Insert(root->rchild, value);
    }
    return root;
}
int heightOfBst(BstNode *root)
{
    if (root == NULL)
        return -1;
    else
        return max(heightOfBst(root->lchild), heightOfBst(root->rchild)) + 1;
}
int main()
{
    BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 14);
    cout << "height is " << heightOfBst(root);
    return 0;
}