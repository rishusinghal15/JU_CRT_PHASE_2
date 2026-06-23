#include<iostream>
using namespace std; 

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        else if (head

                     ->next == NULL) // Only one node
        {
            return head;
        }
        else if (head->next->next == NULL) // In LL, only two nodes
        {
            return head->next;
        }
        else // In LL, 3 or more than 3 nodes
        {
            ListNode *slow = head;
            ListNode *fast = head;

            while (fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    ListNode* ans = obj.middleNode(head);

    cout << "Middle Node = " << ans->val;

    return 0;
}