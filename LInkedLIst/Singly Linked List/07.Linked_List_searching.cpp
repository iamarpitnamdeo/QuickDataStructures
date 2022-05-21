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
bool searchElement(Node *head, int key)
{
    if (head == NULL)
    {
        cout << "Linked List Empty ";
        return false;
    }
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
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
int main()
{

    Node *head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    display(head);
    cout << searchElement(head, 9);
    return 0;
}