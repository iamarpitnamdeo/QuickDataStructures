#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *lchild;
    Node *rchild;
    Node(char data)
    {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
    }
};
Node *insert(Node *root, char value)
{
    if (root == NULL)
    {
        Node *temp = new Node(value);
        root = temp;
    }
    else if (value <= root->data)
    {
        root->lchild = insert(root->lchild, value);
    }
    else
    {
        root->rchild = insert(root->rchild, value);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    preorder(root->lchild);
    preorder(root->rchild);
    cout << root->data << " ";
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    postorder(root->lchild);
    postorder(root->rchild);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 'd');
    root = insert(root, 'b');
    root = insert(root, 'a');
    root = insert(root, 'c');
    root = insert(root, 'f');
    root = insert(root, 'e');
    root = insert(root, 'g');
    cout << "Inorder tree traversal";
    inorder(root);
    cout << "Preorder tree traversal";
    preorder(root);
    cout << "Postorder tree traversal";
    postorder(root);
    return 0;
}