#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
Node *insertEnd(Node *head, int value)
{
    Node *temp = new Node(value);
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
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    display(head);
    return 0;
}