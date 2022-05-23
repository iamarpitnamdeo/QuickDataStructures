// Breadth First Search also called level order traversal of a Binary Search tree
#include <iostream>
#include <queue>
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
void BFS(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        cout << current->data << " ";
        if (current->lchild != NULL)
            q.push(current->lchild);
        if (current->rchild != NULL)
            q.push(current->rchild);
        q.pop();
    }
}
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
int main()
{
    Node *root = NULL;
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');
    cout << "Tree Created";
    BFS(root);
    return 0;
}