#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int v)
    {
        value = v;
        next = NULL;
    }
};

class Stack
{
public:
    Node *head;

    Stack() // default Constructor
    {
        head = NULL;
    }

    // insert at first
    void push(int v)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(v);
            head = newNode;
        }
        else
        {
            Node *newNode = new Node(v);
            newNode->next = head;
            head = newNode;
        }
    }

    // delete at first
    void pop()
    {
        if (head == NULL)
            return;
        else if (head->next == NULL)
        {
            delete (head);
            head = NULL;
        }
        else
        {
            Node *backup = head->next;
            delete (head);
            head = backup;
        }
    }

    // top function
    int top()
    {
        return head->value;
    }

    // empty or not
    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}