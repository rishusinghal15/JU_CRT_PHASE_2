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
    bool searchKey(Node *head, int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            else
            {
                temp = temp->next;
            }
        }
        return false;
    }
};

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    Solution obj;

    if (obj.searchKey(head, key))
    {
        cout << "Key Found";
    }
    else
    {
        cout << "Key Not Found";
    }

    return 0;
}
