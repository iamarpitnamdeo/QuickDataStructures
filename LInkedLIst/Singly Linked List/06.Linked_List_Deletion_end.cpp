#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *insertEnd(Node *head, int item)
{
    Node *temp = new Node(item);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *n = head;
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = temp;
    return head;
}
Node *deleteEnd(Node *head)
{
    Node *n = head;
    Node *p;
    while (n->next != NULL)
    {
        p = n;
        n = n->next;
    }
    p->next = NULL;
    free(n);
    // while (n->next != NULL)
    // {
    //     if (n->next->next == NULL)
    //     {
    //         n->next = NULL;
    //     }
    //     n = n->next;
    // }

    return head;
}
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}
int main()
{
    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    display(head);
    head = deleteEnd(head);
    head = deleteEnd(head);
    display(head);
    return 0;
}