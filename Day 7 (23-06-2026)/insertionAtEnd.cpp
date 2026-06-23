#include<iostream>
using namespace std; 

class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Empty Linked List 
        if(head == NULL)
        {
            Node* newNode = new Node(x); 
            head = newNode; 
        } 
        else 
        {
           Node* newNode = new Node(x); 
           Node* temp = head; 
           while(temp->next != NULL)
           {
              temp = temp->next;  
           }
           temp->next = newNode; 
        }
        return head; 
    }
};

int main()
{
    Solution obj;
    Node *head = NULL;

    head = obj.insertAtEnd(head, 30);
    head = obj.insertAtEnd(head, 20);
    head = obj.insertAtEnd(head, 10);

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } cout << "NULL"; 

    return 0;
}