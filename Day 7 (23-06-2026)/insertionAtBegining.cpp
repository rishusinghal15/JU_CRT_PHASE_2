#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *insertAtFront(Node *head, int x)
    {
        // Empty List
        if (head == NULL)
        {
            Node *newNode = new Node(x);
            head = newNode;
        }
        else
        {
            Node *newNode = new Node(x);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};

int main()
{
    Solution obj;
    Node *head = NULL;

    head = obj.insertAtFront(head, 30);
    head = obj.insertAtFront(head, 20);
    head = obj.insertAtFront(head, 10);

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } cout << "NULL"; 

    return 0;
}