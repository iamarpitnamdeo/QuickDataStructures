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
Node *insertBeginning(Node *head, int value)
{
    Node *temp = new Node(value);
    if(head==NULL)
    {
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}
void printList(Node *head)
{
    cout << "head -> ";
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
    head = insertBeginning(head, 1);
    head = insertBeginning(head, 2);
    head = insertBeginning(head, 3);
    head = insertBeginning(head, 4);
    printList(head);
    return 0;
}