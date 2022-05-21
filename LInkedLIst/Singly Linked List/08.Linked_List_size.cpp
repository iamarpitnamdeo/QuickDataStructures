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
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int size(Node *head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter = counter + 1;
        head = head->next;
    }
    return counter;
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
    cout << size(head);
    return 0;
}