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
Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *nextv = head;
    while (nextv->next != NULL)
    {
        nextv = nextv->next;
    }
    nextv->next = temp;
    return head;
}
Node *deleteHead(Node *head)
{
    Node *temp = head;
    head = temp->next;
    delete temp;
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
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    display(head);
    head = deleteHead(head);
    display(head);
    return 0;
}