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
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->lchild);
    cout << root->data;
    inorder(root->rchild);
}
Node *findMin(Node *root)
{
    while (root->lchild != NULL)
        root = root->lchild;
    return root;
}
Node *Delete(Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->lchild = Delete(root->lchild, data);
    else if (data > root->data)
        root->rchild = Delete(root->rchild, data);
    // found the data at root which will be get deleted
    else
    {
        // case 1: no child
        if (root->lchild == NULL && root->rchild == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2: one child
        else if (root->lchild == NULL)
        {
            Node *temp = root;
            root = root->rchild;
            delete temp;
        }
        else if (root->rchild == NULL)
        {
            Node *temp = root;
            root = root->lchild;
            delete temp;
        }
        // case 3 : both child
        else
        {
            Node *temp = findMin(root->rchild);
            root->data = temp->data;
            root->rchild = Delete(root->rchild, temp->data);
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 11);
    inorder(root);
    root = Delete(root, 5);
    inorder(root);
    return 0;
}