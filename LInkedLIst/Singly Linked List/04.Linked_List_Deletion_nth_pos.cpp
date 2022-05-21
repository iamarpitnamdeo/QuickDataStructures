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
Node *insertBeginning(Node *head, int item)
{
    Node *temp = new Node(item);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}
Node *deleteAtPos(Node *head, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    // Node *n = temp->next;
    // temp->next = n->next;
    temp->next = temp->next->next;
    return head;
}
void display(Node *head)
{
    cout << "head -> ";
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << " NULL";
}
int main()
{
    Node *head = NULL;
    head = insertBeginning(head, 1);
    head = insertBeginning(head, 2);
    head = insertBeginning(head, 3);
    head = insertBeginning(head, 4);
    display(head);
    head = deleteAtPos(head, 4);
    display(head);
    return 0;
}