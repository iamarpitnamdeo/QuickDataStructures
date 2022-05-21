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
Node *insertAtPos(Node *head, int value, int pos)
{
    Node *temp = new Node(value);
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node *n = head;
    for (int i = 0; i < pos - 2; i++)
    {
        n = n->next;
    }
    temp->next = n->next;
    n->next = temp;
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
    cout << " NULL" << endl;
}
int main()
{
    Node *head = NULL;
    head = insertAtPos(head, 1, 1);
    display(head);

    head = insertAtPos(head, 2, 1);
    display(head);

    head = insertAtPos(head, 3, 1);
    display(head);
    head = insertAtPos(head, 4, 2);
    display(head);
    head = insertAtPos(head, 5, 3);
    display(head);
    head = insertAtPos(head, 6, 5);
    display(head);
    return 0;
}