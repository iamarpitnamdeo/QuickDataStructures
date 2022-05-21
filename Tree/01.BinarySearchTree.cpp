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
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *temp = new Node(data);
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
bool search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return search(root->lchild, data);
    }
    else
    {
        return search(root->rchild, data);
    }
}
int main()
{
    Node *root = NULL;
    root = Insert(root, 12);
    root = Insert(root, 6);
    root = Insert(root, 10);
    root = Insert(root, 18);
    root = Insert(root, 4);
    root = Insert(root, 14);
    bool res = search(root, 23);
    if (res == true)
    {
        cout << "Element exist";
    }
    else
    {
        cout << "Element does not exist";
    }

    return 0;
}