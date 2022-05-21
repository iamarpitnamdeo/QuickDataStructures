// complete singly linked list implementation in c++ of integer linked list
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
// insertion at head of linked list passing the head int he aruguments
Node *headInsertion(Node *head, int item)
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
// insetion at the end of the linked list passing the head as argument
Node *tailInsertion(Node *head, int item)
{
    Node *temp = new Node(item);
    if (head == NULL)
    {
        head = temp;
        return NULL;
    }
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    return head;
}
// function to insert randomly at given position
Node *randomInsertion(Node *head, int item, int pos)
{
    Node *temp = new Node(item);
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node *temp2 = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return head;
}
// function to display the linked list passing head node as argument
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
// function to calculate size of linked list
int size(Node *head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}
// function to perform deletion at the head
Node *headDeletion(Node *head)
{
    Node *temp = head;
    head = temp->next;
    delete temp;
    return head;
}
// function to perfrom deletion from the end
Node *tailDeletion(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // delete temp->next;
    temp->next = NULL;
    return head;
    /*
    Node *p;
    while (temp->next != NULL)
    {
        p = temp;
        temp = temp->next;
    }
    p->next = NULL;
    free(temp);
    */
}
// functio to delete any element at random position
Node *randomDeletion(Node *head, int pos)
{

    Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        delete temp;
        return head;
    }
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
int main()
{
    Node *head = NULL;
    head = headInsertion(head, 1);
    head = headInsertion(head, 2);
    head = headInsertion(head, 3);
    head = headInsertion(head, 4);
    head = headInsertion(head, 5);
    cout << "Head insertion" << endl;
    display(head);
    head = tailInsertion(head, 9);
    head = tailInsertion(head, 8);
    head = tailInsertion(head, 7);
    cout << "Tail Insetion" << endl;
    display(head);
    // int n;
    // cout << "Enter position for random insertion";
    // cin >> n;
    // cout << "Enter the value";
    // int val;
    // cin >> val;
    // head = randomInsertion(head, val, n);
    // display(head);
    cout << "Size of linked List is" << size(head) << endl;
    cout << "Head deletion of linked list" << endl;
    head = headDeletion(head);
    display(head);
    head = headDeletion(head);
    display(head);
    cout << "tail deletion of the linked list" << endl;
    head = tailDeletion(head);
    // head = tailDeletion(head);
    display(head);
    cout << "enter the position for deletion" << endl;
    int deletePosition;
    cin>>deletePosition;
    head = randomDeletion(head, deletePosition);
    display(head);
    return 0;
}
