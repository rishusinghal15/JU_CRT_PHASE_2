#include<iostream>
using namespace std; 

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* removeLastNode(Node* head) {
        if(head==NULL)
        {
            return NULL; 
        }
        else if(head->next == NULL)
        {
            delete head; 
            head = NULL; 
        }
        else 
        {
            Node* temp = head; 
            while(temp->next->next != NULL)
            {
                temp = temp->next; 
            }
            delete(temp->next); 
            temp -> next = NULL; 
        }
        return head; 
        
    }
};

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.removeLastNode(head);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}
