#include <iostream>
using namespace std;

// Structure of linked list Node
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    int getCount(Node *head)
    {
        int count = 1;

        if (head == NULL)
        {
            return 0;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Solution obj;
    cout << obj.getCount(head);

    return 0;
}